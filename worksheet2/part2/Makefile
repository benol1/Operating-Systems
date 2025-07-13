AS = nasm
CC = gcc
LD = ld
CFLAGS = -m32 -ffreestanding -Wall -Wextra -nostdlib
LDFLAGS = -m elf_i386 -T source/link.ld
ISO_DIR = iso
BUILD = build
DRIVERS = drivers
SRC = source

all: os.iso

kernel.elf: $(SRC)/loader.asm \
            $(SRC)/kmain.c \
            $(SRC)/idt.c $(SRC)/isr.c $(SRC)/irq.c \
            $(SRC)/keyboard.c $(SRC)/shell.c $(SRC)/fault_handler.c \
            $(DRIVERS)/frame_buffer.c
	mkdir -p $(BUILD)
	$(AS) -f elf $(SRC)/loader.asm -o $(BUILD)/loader.o
	$(CC) $(CFLAGS) -c $(SRC)/kmain.c -o $(BUILD)/kmain.o
	$(CC) $(CFLAGS) -c $(SRC)/idt.c -o $(BUILD)/idt.o
	$(CC) $(CFLAGS) -c $(SRC)/isr.c -o $(BUILD)/isr.o
	$(CC) $(CFLAGS) -c $(SRC)/irq.c -o $(BUILD)/irq.o
	$(CC) $(CFLAGS) -c $(SRC)/keyboard.c -o $(BUILD)/keyboard.o
	$(CC) $(CFLAGS) -c $(SRC)/shell.c -o $(BUILD)/shell.o
	$(CC) $(CFLAGS) -c $(SRC)/fault_handler.c -o $(BUILD)/fault_handler.o
	$(CC) $(CFLAGS) -c $(DRIVERS)/frame_buffer.c -o $(BUILD)/frame_buffer.o
	$(LD) $(LDFLAGS) -o $(BUILD)/kernel.elf \
	    $(BUILD)/loader.o $(BUILD)/kmain.o \
	    $(BUILD)/idt.o $(BUILD)/isr.o $(BUILD)/irq.o \
	    $(BUILD)/keyboard.o $(BUILD)/shell.o $(BUILD)/fault_handler.o \
	    $(BUILD)/frame_buffer.o

os.iso: kernel.elf
	mkdir -p $(ISO_DIR)/boot
	cp $(BUILD)/kernel.elf $(ISO_DIR)/boot/kernel.elf
	grub-mkrescue -o os.iso $(ISO_DIR) > /dev/null 2>&1

run:
	qemu-system-i386 -cdrom os.iso

run-curses:
	qemu-system-i386 -cdrom os.iso -nographic

clean:
	rm -rf $(BUILD) os.iso
