#ifndef FRAME_BUFFER_H
#define FRAME_BUFFER_H

#define FB_ADDRESS 0x000B8000
#define FB_WIDTH 80
#define FB_HEIGHT 25

void fb_clear();
void fb_write(char c, unsigned short pos);
void fb_write_str(const char* str);
void fb_move_cursor(unsigned short x, unsigned short y);
void fb_set_color(unsigned char fg, unsigned char bg);

#endif