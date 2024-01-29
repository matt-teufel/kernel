#define VGA_BASE 0xb8000

#define VGA_BLACK        0
#define VGA_BLUE         1
#define VGA_GREEN        2
#define VGA_CYAN         3
#define VGA_RED          4
#define VGA_MAGENTA      5
#define VGA_BROWN        6
#define VGA_LIGHT_GREY   7
#define VGA_DARK_GREY    8
#define VGA_LIGHT_BLUE   9
#define VGA_LIGHT_GREEN  10
#define VGA_LIGHT_CYAN   11
#define VGA_LIGHT_RED    12
#define VGA_LIGHT_MAGENTA 13
#define VGA_LIGHT_BROWN  14
#define VGA_WHITE        15

#define FG(color) (color)
#define BG(color) (color << 4)

#define LINE(x) (x/80)

extern void VGA_clear(void);
extern void VGA_display_char(char);
extern void VGA_display_str(const char *);
void scroll(void);
