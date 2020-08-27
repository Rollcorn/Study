SYS_EXIT    equ 1
SYS_READ    equ 3
SYS_WRITE   equ 4
STDIN       equ 0
STDOUT      equ 1

segment .data

    msg1 db "Enter a digit ", 0xA, 0xD
    len1 equ $- msg1

    msg2 db "Please enter a second digit", 0xA, 0xD
    len2 equ $- msg2

    msg3 db "The sum is: "
    len3 equ $- msg3

segment .bss

    num1 resb 2
    num2 resb 2
    res resb 1

section .text
    global _start   ;mast be define for using gcc

_start:             ;tells linker the enter point
    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, msg1
    mov edx, len1
    int 0x80

    mov eax, SYS_READ
    mov ebx, STDIN 
    mov ecx, num1
    int 0x80

    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, msg2
    mov edx, len2
    int 0x80

    mov eax, SYS_READ
    mov ebx, STDIN
    mov ecx, num2
    mov edx, 2 
    int 0x80

    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, msg3
    mov edx, len3
    int 0x80

    ;move first number in register eax,secon number in register ebx
    ;and subtract ASCII '0' for conertation in decimal number

    mov eax, [num1]
    sub eax, '0'

    mov ebx, [num2]
    sub ebx, '0'

    ;add eax and ebx
    add eax, ebx
    ;add '0' for convertation sum from decimal system in ASCII
    add eax, '0'

    ;save sum in memory cell res
    mov [res], eax

    mov [res], eax

    ;output the sum
    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, res
    mov edx, 1
    int 0x80

exit: 

    mov eax, SYS_EXIT
    xor ebx, ebx
    int 0x80































