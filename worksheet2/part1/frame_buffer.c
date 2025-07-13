#include "frame_buffer.h"
#include <stdint.h>

static volatile uint16_t* fb = (uint16_t*) FB_ADDRESS;
static uint8_t fb_color = 0x0F; // White on black
static uint16_t cursor_pos = 0;

void fb_set_color(uint8_t fg, uint8_t bg) {
    fb_color = (bg << 4) | (fg & 0x0F);
}

void fb_write(char c, uint16_t pos) {
    fb[pos] = ((uint16_t)fb_color << 8) | c;
}

void fb_write_str(const char* str) {
    while (*str) {
        if (*str == '\n') {
            cursor_pos += FB_WIDTH - (cursor_pos % FB_WIDTH);
        } else {
            fb_write(*str, cursor_pos++);
            if (cursor_pos >= FB_WIDTH * FB_HEIGHT)
                cursor_pos = 0;
        }
        str++;
    }
}

void fb_clear() {
    for (int i = 0; i < FB_WIDTH * FB_HEIGHT; ++i)
        fb[i] = ((uint16_t)fb_color << 8) | ' ';
    cursor_pos = 0;
}

void fb_move_cursor(uint16_t x, uint16_t y) {
    cursor_pos = y * FB_WIDTH + x;
}
