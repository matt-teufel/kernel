#include "interrupts.h"
#include "std.h"
#include <stdint-gcc.h>
#include <stddef.h>

struct IDT_entry IDT[NUM_IRQS];
struct IRQ_entry IRQ[NUM_IRQS];

void irq_dispatch(int interrupt_num) { 
	printk("irq dispatch with num %i\n", interrupt_num);
    if (interrupt_num < 0 || interrupt_num > NUM_IRQS) { 
        printk("Invalid Interrupt number %i\n", interrupt_num);
        return;
    }
	struct IRQ_entry ent = IRQ[interrupt_num];
    if (ent.handler == NULL) { 
		printk("function handler was null");
		return;
	}
	printk("calling function handler\n");
	ent.handler(0, 0, ent.arg); // make this the error num and int num
}

static inline void outb(uint16_t port, uint8_t val)
{
    __asm__ volatile ( "outb %b0, %w1" : : "a"(val), "Nd"(port) : "memory");
    /* There's an outb %al, $imm8 encoding, for compile-time constant port numbers that fit in 8b. (N constraint).
     * Wider immediate constants would be truncated at assemble-time (e.g. "i" constraint).
     * The  outb  %al, %dx  encoding is the only option for all other cases.
     * %1 expands to %dx because  port  is a uint16_t.  %w1 could be used if we had the port number a wider C type */
}

static inline uint8_t inb(uint16_t port)
{
    uint8_t ret;
    __asm__ volatile ( "inb %w1, %b0"
                   : "=a"(ret)
                   : "Nd"(port)
                   : "memory");
    return ret;
}

static inline void io_wait(void)
{
    outb(0x80, 0);
}

/* reinitialize the PIC controllers, giving them specified vector offsets
   rather than 8h and 70h, as configured by default */
 
#define ICW1_ICW4	0x01		/* Indicates that ICW4 will be present */
#define ICW1_SINGLE	0x02		/* Single (cascade) mode */
#define ICW1_INTERVAL4	0x04		/* Call address interval 4 (8) */
#define ICW1_LEVEL	0x08		/* Level triggered (edge) mode */
#define ICW1_INIT	0x10		/* Initialization - required! */
 
#define ICW4_8086	0x01		/* 8086/88 (MCS-80/85) mode */
#define ICW4_AUTO	0x02		/* Auto (normal) EOI */
#define ICW4_BUF_SLAVE	0x08		/* Buffered mode/slave */
#define ICW4_BUF_MASTER	0x0C		/* Buffered mode/master */
#define ICW4_SFNM	0x10		/* Special fully nested (not) */
 
/*
arguments:
	offset1 - vector offset for master PIC
		vectors on the master become offset1..offset1+7
	offset2 - same for slave PIC: offset2..offset2+7
*/
void PIC_remap(int offset1, int offset2)
{
	uint8_t a1, a2;
 
	a1 = inb(PIC1_DATA);                        // save masks
	a2 = inb(PIC2_DATA);
 
	outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);  // starts the initialization sequence (in cascade mode)
	io_wait();
	outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);
	io_wait();
	outb(PIC1_DATA, offset1);                 // ICW2: Master PIC vector offset
	io_wait();
	outb(PIC2_DATA, offset2);                 // ICW2: Slave PIC vector offset
	io_wait();
	outb(PIC1_DATA, 4);                       // ICW3: tell Master PIC that there is a slave PIC at IRQ2 (0000 0100)
	io_wait();
	outb(PIC2_DATA, 2);                       // ICW3: tell Slave PIC its cascade identity (0000 0010)
	io_wait();
 
	outb(PIC1_DATA, ICW4_8086);               // ICW4: have the PICs use 8086 mode (and not 8080 mode)
	io_wait();
	outb(PIC2_DATA, ICW4_8086);
	io_wait();
 
	outb(PIC1_DATA, a1);   // restore saved masks.
	outb(PIC2_DATA, a2);
}

void IRQ_init(void) { 
    int i;
    struct IDT_entry ent;
    PIC_remap(PIC1, PIC2);
    for (i = 0; i < NUM_IRQS; i++){ 
        ent = IDT[i];
        ent.target_selector = GDT_OFFSET; //figure out if this is right
        ent.reserved2 = 0;
        ent.IST = 0; //change stacks for double faults
        ent.P = 1;
        ent.zero = 0;
        ent.DPL = 0;
        ent.type = INT_GATE;
        ent.reserved1 = 0;
    }
    init_IRQ_entries();
    loadIDT();
}

void loadIDT() {
    struct IDT_descriptor idtd;

    idtd.limit = sizeof(IDT) - 1;
    idtd.base = (uint64_t)&IDT;

    asm volatile ("lidt %0" : : "m" (idtd));
}

void set_IDT_entry(int idx, uintptr_t entryPoint)
{ 
    IDT[idx].target_offset_upper = (entryPoint >> 32) & 0xFFFFFFFF;
    IDT[idx].target_offset_middle = (entryPoint >> 16) & 0xFFFF;
    IDT[idx].target_offset_lower = entryPoint & 0xFFFF;
}

void IRQ_set_mask(uint8_t IRQline) {
    uint16_t port;
    uint8_t value;
 
    if(IRQline < 8) {
        port = PIC1_DATA;
    } else {
        port = PIC2_DATA;
        IRQline -= 8;
    }
    value = inb(port) | (1 << IRQline);
    outb(port, value);        
}
 
void IRQ_clear_mask(uint8_t IRQline) {
    uint16_t port;
    uint8_t value;
 
    if(IRQline < 8) {
        port = PIC1_DATA;
    } else {
        port = PIC2_DATA;
        IRQline -= 8;
    }
    value = inb(port) & ~(1 << IRQline);
    outb(port, value);        
}

int IRQ_get_mask(int IRQline)
{
    return 0;
}
void IRQ_end_of_interrupt(int irq)
{ 
    return;
}

void IRQ_set_handler(int irq, irq_handler_t handler, void *arg)
{    
    IRQ[irq].handler = handler;
	IRQ[irq].handler = arg;
}

void init_IRQ_entries() {
	set_IDT_entry(0, (uintptr_t)irq_entry_0);
	set_IDT_entry(1, (uintptr_t)irq_entry_1);
	set_IDT_entry(2, (uintptr_t)irq_entry_2);
	set_IDT_entry(3, (uintptr_t)irq_entry_3);
	set_IDT_entry(4, (uintptr_t)irq_entry_4);
	set_IDT_entry(5, (uintptr_t)irq_entry_5);
	set_IDT_entry(6, (uintptr_t)irq_entry_6);
	set_IDT_entry(7, (uintptr_t)irq_entry_7);
	set_IDT_entry(8, (uintptr_t)irq_entry_8);
	set_IDT_entry(9, (uintptr_t)irq_entry_9);
	set_IDT_entry(10, (uintptr_t)irq_entry_10);
	set_IDT_entry(11, (uintptr_t)irq_entry_11);
	set_IDT_entry(12, (uintptr_t)irq_entry_12);
	set_IDT_entry(13, (uintptr_t)irq_entry_13);
	set_IDT_entry(14, (uintptr_t)irq_entry_14);
	set_IDT_entry(15, (uintptr_t)irq_entry_15);
	set_IDT_entry(16, (uintptr_t)irq_entry_16);
	set_IDT_entry(17, (uintptr_t)irq_entry_17);
	set_IDT_entry(18, (uintptr_t)irq_entry_18);
	set_IDT_entry(19, (uintptr_t)irq_entry_19);
	set_IDT_entry(20, (uintptr_t)irq_entry_20);
	set_IDT_entry(21, (uintptr_t)irq_entry_21);
	set_IDT_entry(22, (uintptr_t)irq_entry_22);
	set_IDT_entry(23, (uintptr_t)irq_entry_23);
	set_IDT_entry(24, (uintptr_t)irq_entry_24);
	set_IDT_entry(25, (uintptr_t)irq_entry_25);
	set_IDT_entry(26, (uintptr_t)irq_entry_26);
	set_IDT_entry(27, (uintptr_t)irq_entry_27);
	set_IDT_entry(28, (uintptr_t)irq_entry_28);
	set_IDT_entry(29, (uintptr_t)irq_entry_29);
	set_IDT_entry(30, (uintptr_t)irq_entry_30);
	set_IDT_entry(31, (uintptr_t)irq_entry_31);
	set_IDT_entry(32, (uintptr_t)irq_entry_32);
	set_IDT_entry(33, (uintptr_t)irq_entry_33);
	set_IDT_entry(34, (uintptr_t)irq_entry_34);
	set_IDT_entry(35, (uintptr_t)irq_entry_35);
	set_IDT_entry(36, (uintptr_t)irq_entry_36);
	set_IDT_entry(37, (uintptr_t)irq_entry_37);
	set_IDT_entry(38, (uintptr_t)irq_entry_38);
	set_IDT_entry(39, (uintptr_t)irq_entry_39);
	set_IDT_entry(40, (uintptr_t)irq_entry_40);
	set_IDT_entry(41, (uintptr_t)irq_entry_41);
	set_IDT_entry(42, (uintptr_t)irq_entry_42);
	set_IDT_entry(43, (uintptr_t)irq_entry_43);
	set_IDT_entry(44, (uintptr_t)irq_entry_44);
	set_IDT_entry(45, (uintptr_t)irq_entry_45);
	set_IDT_entry(46, (uintptr_t)irq_entry_46);
	set_IDT_entry(47, (uintptr_t)irq_entry_47);
	set_IDT_entry(48, (uintptr_t)irq_entry_48);
	set_IDT_entry(49, (uintptr_t)irq_entry_49);
	set_IDT_entry(50, (uintptr_t)irq_entry_50);
	set_IDT_entry(51, (uintptr_t)irq_entry_51);
	set_IDT_entry(52, (uintptr_t)irq_entry_52);
	set_IDT_entry(53, (uintptr_t)irq_entry_53);
	set_IDT_entry(54, (uintptr_t)irq_entry_54);
	set_IDT_entry(55, (uintptr_t)irq_entry_55);
	set_IDT_entry(56, (uintptr_t)irq_entry_56);
	set_IDT_entry(57, (uintptr_t)irq_entry_57);
	set_IDT_entry(58, (uintptr_t)irq_entry_58);
	set_IDT_entry(59, (uintptr_t)irq_entry_59);
	set_IDT_entry(60, (uintptr_t)irq_entry_60);
	set_IDT_entry(61, (uintptr_t)irq_entry_61);
	set_IDT_entry(62, (uintptr_t)irq_entry_62);
	set_IDT_entry(63, (uintptr_t)irq_entry_63);
	set_IDT_entry(64, (uintptr_t)irq_entry_64);
	set_IDT_entry(65, (uintptr_t)irq_entry_65);
	set_IDT_entry(66, (uintptr_t)irq_entry_66);
	set_IDT_entry(67, (uintptr_t)irq_entry_67);
	set_IDT_entry(68, (uintptr_t)irq_entry_68);
	set_IDT_entry(69, (uintptr_t)irq_entry_69);
	set_IDT_entry(70, (uintptr_t)irq_entry_70);
	set_IDT_entry(71, (uintptr_t)irq_entry_71);
	set_IDT_entry(72, (uintptr_t)irq_entry_72);
	set_IDT_entry(73, (uintptr_t)irq_entry_73);
	set_IDT_entry(74, (uintptr_t)irq_entry_74);
	set_IDT_entry(75, (uintptr_t)irq_entry_75);
	set_IDT_entry(76, (uintptr_t)irq_entry_76);
	set_IDT_entry(77, (uintptr_t)irq_entry_77);
	set_IDT_entry(78, (uintptr_t)irq_entry_78);
	set_IDT_entry(79, (uintptr_t)irq_entry_79);
	set_IDT_entry(80, (uintptr_t)irq_entry_80);
	set_IDT_entry(81, (uintptr_t)irq_entry_81);
	set_IDT_entry(82, (uintptr_t)irq_entry_82);
	set_IDT_entry(83, (uintptr_t)irq_entry_83);
	set_IDT_entry(84, (uintptr_t)irq_entry_84);
	set_IDT_entry(85, (uintptr_t)irq_entry_85);
	set_IDT_entry(86, (uintptr_t)irq_entry_86);
	set_IDT_entry(87, (uintptr_t)irq_entry_87);
	set_IDT_entry(88, (uintptr_t)irq_entry_88);
	set_IDT_entry(89, (uintptr_t)irq_entry_89);
	set_IDT_entry(90, (uintptr_t)irq_entry_90);
	set_IDT_entry(91, (uintptr_t)irq_entry_91);
	set_IDT_entry(92, (uintptr_t)irq_entry_92);
	set_IDT_entry(93, (uintptr_t)irq_entry_93);
	set_IDT_entry(94, (uintptr_t)irq_entry_94);
	set_IDT_entry(95, (uintptr_t)irq_entry_95);
	set_IDT_entry(96, (uintptr_t)irq_entry_96);
	set_IDT_entry(97, (uintptr_t)irq_entry_97);
	set_IDT_entry(98, (uintptr_t)irq_entry_98);
	set_IDT_entry(99, (uintptr_t)irq_entry_99);
	set_IDT_entry(100, (uintptr_t)irq_entry_100);
	set_IDT_entry(101, (uintptr_t)irq_entry_101);
	set_IDT_entry(102, (uintptr_t)irq_entry_102);
	set_IDT_entry(103, (uintptr_t)irq_entry_103);
	set_IDT_entry(104, (uintptr_t)irq_entry_104);
	set_IDT_entry(105, (uintptr_t)irq_entry_105);
	set_IDT_entry(106, (uintptr_t)irq_entry_106);
	set_IDT_entry(107, (uintptr_t)irq_entry_107);
	set_IDT_entry(108, (uintptr_t)irq_entry_108);
	set_IDT_entry(109, (uintptr_t)irq_entry_109);
	set_IDT_entry(110, (uintptr_t)irq_entry_110);
	set_IDT_entry(111, (uintptr_t)irq_entry_111);
	set_IDT_entry(112, (uintptr_t)irq_entry_112);
	set_IDT_entry(113, (uintptr_t)irq_entry_113);
	set_IDT_entry(114, (uintptr_t)irq_entry_114);
	set_IDT_entry(115, (uintptr_t)irq_entry_115);
	set_IDT_entry(116, (uintptr_t)irq_entry_116);
	set_IDT_entry(117, (uintptr_t)irq_entry_117);
	set_IDT_entry(118, (uintptr_t)irq_entry_118);
	set_IDT_entry(119, (uintptr_t)irq_entry_119);
	set_IDT_entry(120, (uintptr_t)irq_entry_120);
	set_IDT_entry(121, (uintptr_t)irq_entry_121);
	set_IDT_entry(122, (uintptr_t)irq_entry_122);
	set_IDT_entry(123, (uintptr_t)irq_entry_123);
	set_IDT_entry(124, (uintptr_t)irq_entry_124);
	set_IDT_entry(125, (uintptr_t)irq_entry_125);
	set_IDT_entry(126, (uintptr_t)irq_entry_126);
	set_IDT_entry(127, (uintptr_t)irq_entry_127);
	set_IDT_entry(128, (uintptr_t)irq_entry_128);
	set_IDT_entry(129, (uintptr_t)irq_entry_129);
	set_IDT_entry(130, (uintptr_t)irq_entry_130);
	set_IDT_entry(131, (uintptr_t)irq_entry_131);
	set_IDT_entry(132, (uintptr_t)irq_entry_132);
	set_IDT_entry(133, (uintptr_t)irq_entry_133);
	set_IDT_entry(134, (uintptr_t)irq_entry_134);
	set_IDT_entry(135, (uintptr_t)irq_entry_135);
	set_IDT_entry(136, (uintptr_t)irq_entry_136);
	set_IDT_entry(137, (uintptr_t)irq_entry_137);
	set_IDT_entry(138, (uintptr_t)irq_entry_138);
	set_IDT_entry(139, (uintptr_t)irq_entry_139);
	set_IDT_entry(140, (uintptr_t)irq_entry_140);
	set_IDT_entry(141, (uintptr_t)irq_entry_141);
	set_IDT_entry(142, (uintptr_t)irq_entry_142);
	set_IDT_entry(143, (uintptr_t)irq_entry_143);
	set_IDT_entry(144, (uintptr_t)irq_entry_144);
	set_IDT_entry(145, (uintptr_t)irq_entry_145);
	set_IDT_entry(146, (uintptr_t)irq_entry_146);
	set_IDT_entry(147, (uintptr_t)irq_entry_147);
	set_IDT_entry(148, (uintptr_t)irq_entry_148);
	set_IDT_entry(149, (uintptr_t)irq_entry_149);
	set_IDT_entry(150, (uintptr_t)irq_entry_150);
	set_IDT_entry(151, (uintptr_t)irq_entry_151);
	set_IDT_entry(152, (uintptr_t)irq_entry_152);
	set_IDT_entry(153, (uintptr_t)irq_entry_153);
	set_IDT_entry(154, (uintptr_t)irq_entry_154);
	set_IDT_entry(155, (uintptr_t)irq_entry_155);
	set_IDT_entry(156, (uintptr_t)irq_entry_156);
	set_IDT_entry(157, (uintptr_t)irq_entry_157);
	set_IDT_entry(158, (uintptr_t)irq_entry_158);
	set_IDT_entry(159, (uintptr_t)irq_entry_159);
	set_IDT_entry(160, (uintptr_t)irq_entry_160);
	set_IDT_entry(161, (uintptr_t)irq_entry_161);
	set_IDT_entry(162, (uintptr_t)irq_entry_162);
	set_IDT_entry(163, (uintptr_t)irq_entry_163);
	set_IDT_entry(164, (uintptr_t)irq_entry_164);
	set_IDT_entry(165, (uintptr_t)irq_entry_165);
	set_IDT_entry(166, (uintptr_t)irq_entry_166);
	set_IDT_entry(167, (uintptr_t)irq_entry_167);
	set_IDT_entry(168, (uintptr_t)irq_entry_168);
	set_IDT_entry(169, (uintptr_t)irq_entry_169);
	set_IDT_entry(170, (uintptr_t)irq_entry_170);
	set_IDT_entry(171, (uintptr_t)irq_entry_171);
	set_IDT_entry(172, (uintptr_t)irq_entry_172);
	set_IDT_entry(173, (uintptr_t)irq_entry_173);
	set_IDT_entry(174, (uintptr_t)irq_entry_174);
	set_IDT_entry(175, (uintptr_t)irq_entry_175);
	set_IDT_entry(176, (uintptr_t)irq_entry_176);
	set_IDT_entry(177, (uintptr_t)irq_entry_177);
	set_IDT_entry(178, (uintptr_t)irq_entry_178);
	set_IDT_entry(179, (uintptr_t)irq_entry_179);
	set_IDT_entry(180, (uintptr_t)irq_entry_180);
	set_IDT_entry(181, (uintptr_t)irq_entry_181);
	set_IDT_entry(182, (uintptr_t)irq_entry_182);
	set_IDT_entry(183, (uintptr_t)irq_entry_183);
	set_IDT_entry(184, (uintptr_t)irq_entry_184);
	set_IDT_entry(185, (uintptr_t)irq_entry_185);
	set_IDT_entry(186, (uintptr_t)irq_entry_186);
	set_IDT_entry(187, (uintptr_t)irq_entry_187);
	set_IDT_entry(188, (uintptr_t)irq_entry_188);
	set_IDT_entry(189, (uintptr_t)irq_entry_189);
	set_IDT_entry(190, (uintptr_t)irq_entry_190);
	set_IDT_entry(191, (uintptr_t)irq_entry_191);
	set_IDT_entry(192, (uintptr_t)irq_entry_192);
	set_IDT_entry(193, (uintptr_t)irq_entry_193);
	set_IDT_entry(194, (uintptr_t)irq_entry_194);
	set_IDT_entry(195, (uintptr_t)irq_entry_195);
	set_IDT_entry(196, (uintptr_t)irq_entry_196);
	set_IDT_entry(197, (uintptr_t)irq_entry_197);
	set_IDT_entry(198, (uintptr_t)irq_entry_198);
	set_IDT_entry(199, (uintptr_t)irq_entry_199);
	set_IDT_entry(200, (uintptr_t)irq_entry_200);
	set_IDT_entry(201, (uintptr_t)irq_entry_201);
	set_IDT_entry(202, (uintptr_t)irq_entry_202);
	set_IDT_entry(203, (uintptr_t)irq_entry_203);
	set_IDT_entry(204, (uintptr_t)irq_entry_204);
	set_IDT_entry(205, (uintptr_t)irq_entry_205);
	set_IDT_entry(206, (uintptr_t)irq_entry_206);
	set_IDT_entry(207, (uintptr_t)irq_entry_207);
	set_IDT_entry(208, (uintptr_t)irq_entry_208);
	set_IDT_entry(209, (uintptr_t)irq_entry_209);
	set_IDT_entry(210, (uintptr_t)irq_entry_210);
	set_IDT_entry(211, (uintptr_t)irq_entry_211);
	set_IDT_entry(212, (uintptr_t)irq_entry_212);
	set_IDT_entry(213, (uintptr_t)irq_entry_213);
	set_IDT_entry(214, (uintptr_t)irq_entry_214);
	set_IDT_entry(215, (uintptr_t)irq_entry_215);
	set_IDT_entry(216, (uintptr_t)irq_entry_216);
	set_IDT_entry(217, (uintptr_t)irq_entry_217);
	set_IDT_entry(218, (uintptr_t)irq_entry_218);
	set_IDT_entry(219, (uintptr_t)irq_entry_219);
	set_IDT_entry(220, (uintptr_t)irq_entry_220);
	set_IDT_entry(221, (uintptr_t)irq_entry_221);
	set_IDT_entry(222, (uintptr_t)irq_entry_222);
	set_IDT_entry(223, (uintptr_t)irq_entry_223);
	set_IDT_entry(224, (uintptr_t)irq_entry_224);
	set_IDT_entry(225, (uintptr_t)irq_entry_225);
	set_IDT_entry(226, (uintptr_t)irq_entry_226);
	set_IDT_entry(227, (uintptr_t)irq_entry_227);
	set_IDT_entry(228, (uintptr_t)irq_entry_228);
	set_IDT_entry(229, (uintptr_t)irq_entry_229);
	set_IDT_entry(230, (uintptr_t)irq_entry_230);
	set_IDT_entry(231, (uintptr_t)irq_entry_231);
	set_IDT_entry(232, (uintptr_t)irq_entry_232);
	set_IDT_entry(233, (uintptr_t)irq_entry_233);
	set_IDT_entry(234, (uintptr_t)irq_entry_234);
	set_IDT_entry(235, (uintptr_t)irq_entry_235);
	set_IDT_entry(236, (uintptr_t)irq_entry_236);
	set_IDT_entry(237, (uintptr_t)irq_entry_237);
	set_IDT_entry(238, (uintptr_t)irq_entry_238);
	set_IDT_entry(239, (uintptr_t)irq_entry_239);
	set_IDT_entry(240, (uintptr_t)irq_entry_240);
	set_IDT_entry(241, (uintptr_t)irq_entry_241);
	set_IDT_entry(242, (uintptr_t)irq_entry_242);
	set_IDT_entry(243, (uintptr_t)irq_entry_243);
	set_IDT_entry(244, (uintptr_t)irq_entry_244);
	set_IDT_entry(245, (uintptr_t)irq_entry_245);
	set_IDT_entry(246, (uintptr_t)irq_entry_246);
	set_IDT_entry(247, (uintptr_t)irq_entry_247);
	set_IDT_entry(248, (uintptr_t)irq_entry_248);
	set_IDT_entry(249, (uintptr_t)irq_entry_249);
	set_IDT_entry(250, (uintptr_t)irq_entry_250);
	set_IDT_entry(251, (uintptr_t)irq_entry_251);
	set_IDT_entry(252, (uintptr_t)irq_entry_252);
	set_IDT_entry(253, (uintptr_t)irq_entry_253);
	set_IDT_entry(254, (uintptr_t)irq_entry_254);
	set_IDT_entry(255, (uintptr_t)irq_entry_255);
}