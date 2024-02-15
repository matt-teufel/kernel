#include <stdint-gcc.h>
#define PS2_DATA 0x60
#define PS2_CMD 0x64
#define PS2_STATUS PS2_CMD
#define DISABLE_P1 0xAD
#define DISABLE_P2 0xA7
#define ENABLE_P1 0xAE

#define READ_CFG 0x20
#define WRITE_CFG 0x60

#define CFG_ENABLE_IRQ1 0x1
#define CFG_ENABLE_IRQ2 0x2
#define CFG_DISABLE_C1 0x10
#define CFG_DISABLE_C2 0x20

#define PS2_STATUS_OUTPUT 0x1
#define PS2_STATUS_INPUT 0x2

#define KB_RST 0xFF
#define SET_QWERTY 0xF1

#define ACK 0xFA

#define SCAN_NULL       0x00
#define SCAN_ESC        0x01
#define SCAN_1          0x02
#define SCAN_2          0x03
#define SCAN_3          0x04
#define SCAN_4          0x05
#define SCAN_5          0x06
#define SCAN_6          0x07
#define SCAN_7          0x08
#define SCAN_8          0x09
#define SCAN_9          0x0A
#define SCAN_0          0x0B
#define SCAN_MINUS      0x0C
#define SCAN_EQUAL      0x0D
#define SCAN_BACKSPACE  0x0E
#define SCAN_TAB        0x0F
#define SCAN_Q          0x10
#define SCAN_W          0x11
#define SCAN_E          0x12
#define SCAN_R          0x13
#define SCAN_T          0x14
#define SCAN_Y          0x15
#define SCAN_U          0x16
#define SCAN_I          0x17
#define SCAN_O          0x18
#define SCAN_P          0x19
#define SCAN_LEFT_BRACKET   0x1A
#define SCAN_RIGHT_BRACKET  0x1B
#define SCAN_ENTER      0x1C
#define SCAN_LEFT_CTRL  0x1D
#define SCAN_A          0x1E
#define SCAN_S          0x1F
#define SCAN_D          0x20
#define SCAN_F          0x21
#define SCAN_G          0x22
#define SCAN_H          0x23
#define SCAN_J          0x24
#define SCAN_K          0x25
#define SCAN_L          0x26
#define SCAN_SEMICOLON  0x27
#define SCAN_SINGLE_QUOTE  0x28
#define SCAN_BACK_TICK  0x29
#define SCAN_LEFT_SHIFT 0x2A
#define SCAN_BACKSLASH  0x2B
#define SCAN_Z          0x2C
#define SCAN_X          0x2D
#define SCAN_C          0x2E
#define SCAN_V          0x2F
#define SCAN_B          0x30
#define SCAN_N          0x31
#define SCAN_M          0x32
#define SCAN_COMMA      0x33
#define SCAN_PERIOD     0x34
#define SCAN_FORWARD_SLASH  0x35
#define SCAN_RIGHT_SHIFT 0x36
#define SCAN_KEYPAD_ASTERISK 0x37
#define SCAN_LEFT_ALT   0x38
#define SCAN_SPACE      0x39
#define SCAN_CAPS_LOCK  0x3A
#define SCAN_F1         0x3B
#define SCAN_F2         0x3C
#define SCAN_F3         0x3D
#define SCAN_F4         0x3E
#define SCAN_F5         0x3F
#define SCAN_F6         0x40
#define SCAN_F7         0x41
#define SCAN_F8         0x42
#define SCAN_F9         0x43
#define SCAN_F10        0x44
#define SCAN_NUM_LOCK   0x45
#define SCAN_SCROLL_LOCK    0x46
#define SCAN_KEYPAD_7   0x47
#define SCAN_KEYPAD_8   0x48
#define SCAN_KEYPAD_9   0x49
#define SCAN_KEYPAD_MINUS   0x4A
#define SCAN_KEYPAD_4   0x4B
#define SCAN_KEYPAD_5   0x4C
#define SCAN_KEYPAD_6   0x4D
#define SCAN_KEYPAD_PLUS    0x4E
#define SCAN_KEYPAD_1   0x4F
#define SCAN_KEYPAD_2   0x50
#define SCAN_KEYPAD_3   0x51
#define SCAN_KEYPAD_0   0x52
#define SCAN_KEYPAD_PERIOD  0x53
#define SCAN_ALT_PRINTSCREEN 0x54
#define SCAN_F11        0x57
#define SCAN_F12        0x58
#define SCAN_LEFT_SHIFT_RELEASE 0xAA
#define SCAN_RIGHT_SHIFT_RELEASE 0xB6

extern void ps2_init(void);
static char ps2_poll_read(void);
static inline uint8_t inb(uint16_t port);
static inline void outb(uint16_t port, uint8_t val);
extern char read_kb(void);
extern void enable_kb(void);

