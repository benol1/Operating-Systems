#include "D:\OSFinal\worksheet2\part1\frame_buffer.h"

void kmain() {
    fb_set_color(15, 0); // white on black
    fb_clear();
    fb_write_str("Worksheet 2 Part 1 Booted!\n");
    fb_write_str("Framebuffer is working.\n");
    while (1);
}
