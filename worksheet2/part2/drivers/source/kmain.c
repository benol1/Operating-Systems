#include "idt.h"
#include "isr.h"
#include "irq.h"
#include "keyboard.h"
#include "shell.h"
#include "../drivers/frame_buffer.h"

void irq_handler() {
    // Only needed for keyboard IRQ (handled elsewhere)
    // Send EOI to PIC
    asm volatile ("movb $0x20, %al; outb %al, $0x20");
}

void kmain() {
    fb_set_color(15, 0);
    fb_clear();
    idt_install();
    isr_install();
    irq_install();
    shell_start();
    while (1);
}
