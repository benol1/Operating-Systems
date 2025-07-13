#include "idt.h"
#include "irq.h"

extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();

#define PIC1_COMMAND 0x20
#define PIC1_DATA    0x21
#define PIC2_COMMAND 0xA0
#define PIC2_DATA    0xA1

static inline void outb(unsigned short port, unsigned char val) {
    asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

void irq_remap(void) {
    outb(PIC1_COMMAND, 0x11);
    outb(PIC2_COMMAND, 0x11);
    outb(PIC1_DATA, 0x20);
    outb(PIC2_DATA, 0x28);
    outb(PIC1_DATA, 0x04);
    outb(PIC2_DATA, 0x02);
    outb(PIC1_DATA, 0x01);
    outb(PIC2_DATA, 0x01);
    outb(PIC1_DATA, 0x0);
    outb(PIC2_DATA, 0x0);
}

void irq_install() {
    irq_remap();
    idt_set_gate(32, (unsigned)irq0,  0x08, 0x8E);
    idt_set_gate(33, (unsigned)irq1,  0x08, 0x8E);
    idt_set_gate(34, (unsigned)irq2,  0x08, 0x8E);
    idt_set_gate(35, (unsigned)irq3,  0x08, 0x8E);
    idt_set_gate(36, (unsigned)irq4,  0x08, 0x8E);
    idt_set_gate(37, (unsigned)irq5,  0x08, 0x8E);
    idt_set_gate(38, (unsigned)irq6,  0x08, 0x8E);
    idt_set_gate(39, (unsigned)irq7,  0x08, 0x8E);
    idt_set_gate(40, (unsigned)irq8,  0x08, 0x8E);
    idt_set_gate(41, (unsigned)irq9,  0x08, 0x8E);
    idt_set_gate(42, (unsigned)irq10, 0x08, 0x8E);
    idt_set_gate(43, (unsigned)irq11, 0x08, 0x8E);
    idt_set_gate(44, (unsigned)irq12, 0x08, 0x8E);
    idt_set_gate(45, (unsigned)irq13, 0x08, 0x8E);
    idt_set_gate(46, (unsigned)irq14, 0x08, 0x8E);
    idt_set_gate(47, (unsigned)irq15, 0x08, 0x8E);
}
