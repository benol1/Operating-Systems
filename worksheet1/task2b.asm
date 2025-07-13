section .data
section .bss

section .text
global main

main:
    mov ecx, 10
    mov eax, 0
.print_even:
    test eax, 1
    jnz .next
    ; would print eax here
.next:
    inc eax
    loop .print_even
    ret
