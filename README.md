

## Structure

- `worksheet1/` : Assembly and C tasks for OS Worksheet 1 
- `worksheet2/part1/` : QEMU-bootable framebuffer OS 
- `worksheet2/part2/` : Bootable OS with interrupts, keyboard IRQ, and shell (QEMU)

## Quick Usage

### Worksheet 1

```bash
cd worksheet1
make           
./task3        

cd worksheet2/part1
make
make run       

cd ../part2
make
make run       

Dependencies
Ubuntu/WSL: sudo apt install make gcc nasm qemu grub-common xorriso gcc-multilib

Each subfolder includes a README for specific instructions and learning points.

