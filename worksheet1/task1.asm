section .data
    msg db "Task 1: Add 2+3=", 0

section .bss

section .text
    global main

main:
    push ebp
    mov ebp, esp

    ; Print message
    mov eax, msg
    push eax
    call print_string
    add esp, 4

    mov eax, 2
    add eax, 3

    push eax
    call print_int
    add esp, 4

    call print_nl

    mov eax, 0
    leave
    ret

%include "asm_io.inc"
