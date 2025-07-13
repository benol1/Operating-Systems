section .data
section .bss

section .text
global main

main:
    mov ecx, 10
.loop:
    ; do something in the loop (e.g. add numbers)
    loop .loop
    ret
