section .data
    prompt db "Enter a number: ", 0

section .bss

section .text
global main
extern printf
extern scanf

main:
    ; would print prompt and read number using printf/scanf or OS syscalls
    ret
