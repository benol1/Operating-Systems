#include "keyboard.h"
#include "../drivers/frame_buffer.h"

#define KBD_DATA_PORT 0x60

char keymap[128] = {
  0,  27, '1','2','3','4','5','6','7','8','9','0','-','=', '\b',
  '\t','q','w','e','r','t','y','u','i','o','p','[',']','\n', 0,
  'a','s','d','f','g','h','j','k','l',';','\'','`', 0, '\\',
  'z','x','c','v','b','n','m',',','.','/', 0, '*', 0, ' ', 0,
  // rest zero
};

static volatile char last_char = 0;

static inline unsigned char inb(unsigned short port) {
    unsigned char ret;
    asm volatile("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

void keyboard_handler() {
    unsigned char scancode = inb(KBD_DATA_PORT);
    if (scancode & 0x80) {
        // Key released
    } else {
        last_char = keymap[scancode];
        if (last_char) {
            char str[2] = {last_char, 0};
            fb_write_str(str);
        }
    }
}

void keyboard_install() {
    // Nothing needed here; handler will be called from IRQ1
}

char keyboard_readchar() {
    char c = last_char;
    last_char = 0;
    return c;
}
