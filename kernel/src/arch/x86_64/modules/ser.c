#include "ser.h"
#include "interrupts.h"
#include "std.h"
#include <stdint-gcc.h>

uint8_t idle_state = 0;
struct State * global_state;

static void init_state(struct State * state)
{
    state->consumer = &state->buff[0];
    state->producer = &state->buff[0];
}

int serial_received() {
   return inb(PORT + 5) & 1;
}
 
char read_serial() {
   while (serial_received() == 0);
 
   return inb(PORT);
}

int is_transmit_empty() {
   return inb(PORT + 5) & 0x20;
}
 
// void write_serial(char a) {
//    while (is_transmit_empty() == 0);
//    outb(PORT,a);
// }

void hw_write(struct State * s) { 
   if(!idle_state) { 
      // printk("polling empty transmission\n");
      while(is_transmit_empty() == 0);
      // printk("polling done, changing state\n");
      idle_state = 1;
   }
   if(idle_state) { 
      idle_state = 0;
      // printk("serial consuming and writing to hardware\n");
      consumer_next(s);
   }
}


void serial_handler(int interrupt_num, int error_code, void * arg) 
{
   // printk("serial handler\n");
   uint8_t status = (inb(PORT+2) > 1) & IIR_MASK;
   // printk("status %u\n", status);
   uint8_t line_status = inb(PORT + 5);
   // printk("line status: %l\n", line_status);
   if (status == IIR_LINE) { 
      // printk("clearning line register\n");
      inb(PORT + 5);
   } else if (status == IIR_TX) {
      // printk("transmit clear\n");
      idle_state = 1;
      struct State * s = (struct State *)arg;
      hw_write(s); 
   } else {
      // printk("different interrupt in serial handler %u", status);
   }
}


static void consume_byte(char c) 
{
   outb(PORT,c);
}

static void consumer_next(struct State * state)
{
    if (state->consumer == state->producer){
      return;
    }
    
    consume_byte(*state->consumer++);
    if (state->consumer >= &state->buff[BUFF_SIZE])
        state->consumer = &state->buff[0];
}

static int producer_add_char(char toAdd, struct State * state) 
{
    if (state->producer == state->consumer -1 || 
        (state->consumer == &state->buff[0] && state->producer == &state->buff[BUFF_SIZE-1])){
         return -1;
        }
    *state->producer++ = toAdd;
    if (state->producer >= &state->buff[BUFF_SIZE])
        state->producer = &state->buff[0];
   return 0;
}

void SER_init(void) 
{
   outb(PORT + 1, 0x00);    // Disable all interrupts
   outb(PORT + 3, 0x80);    // Enable DLAB (set baud rate divisor)
   outb(PORT + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
   outb(PORT + 1, 0x00);    // 
   outb(PORT + 3, 0x03);    // 8 bits, no parity, one stop bit
   outb(PORT + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
   outb(PORT + 4, 0x0B);    // IRQs enabled, RTS/DSR set
   outb(PORT + 4, 0x1E);    // Set in loopback mode, test the serial chip
   outb(PORT + 0, 0xAE);    // Test serial chip (send byte 0xAE and check if serial returns same byte)

   outb(PORT + 1, 0x2); //enable tx empty interrupts 
 
   // Check if serial is faulty (i.e: not same byte as sent)
   if(inb(PORT + 0) != 0xAE) {
      // printk("serial is faulty\n");
      return;
   }
 
   // If serial is not faulty set it in normal operation mode
   // (not-loopback with IRQs enabled and OUT#1 and OUT#2 bits enabled)
   outb(PORT + 4, 0x0F);

   static struct State s;
   global_state = &s;
   IRQ_set_handler(IRQ4, serial_handler, &s);
   IRQ_clear_mask(4);
   // printk("end of serial init\n");
}




int SER_write(const char * buff, int len) 
{
   // printk("inside serial write\n");
   uint8_t enable_interrupts = 0;
   if (are_interrupts_enabled()){ 
        enable_interrupts = 1;
        CLI();
   }
   int i;
   for (i = 0; i < len; i++) { 
      if(producer_add_char(buff[i], global_state) == -1){
         break;
      }
   }
   hw_write(global_state);
   if(enable_interrupts == 1){
        STI();
   }
   return i;
}