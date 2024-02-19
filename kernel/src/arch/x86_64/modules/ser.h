#define BUFF_SIZE 16
#define PORT 0x3f8          // COM1

#define IIR_TX 0x1
#define IIR_LINE 0x3
#define IIR_MASK 0x7

struct State { 
    char buff[BUFF_SIZE];
    char * consumer, *producer;
};

extern void SER_init(void);
extern int SER_write(const char *buff, int len);
static void consumer_next(struct State * state);