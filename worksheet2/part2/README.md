# Worksheet 2 – Part 2

This worksheet boots a 32-bit kernel with interrupt handling, keyboard input, and a simple shell in QEMU.

## Build and Run

**Requirements:**
```bash
sudo apt update
sudo apt install make gcc gcc-multilib nasm qemu grub-common xorriso

To build and run:
make
make run

To clean:
make clean