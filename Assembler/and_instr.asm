section .text
    global _start       ;must be define for using gcc
    
_start:                 ;tell linler the inter point
    mov ax, 9h          ;store 8 in register AX
    and ax, 1           ;execute operation AND with AX
    jz evnn
    mov eax, 4          ;system call number (sys_write)
    mov ebx, 1          ;file descriptor
    mov ecx, odd_msg    ;massage for writing
    mov edx, len2
    int 0x80            ;core call
    jmp outprog

evnn:

    mov ah, 09h
    mov eax, 4          ;system call number (sys_write)
    mov ebx, 1          ;file descriptor (stdout)
    mov ecx, even_msg   ;massage for writing
    mov edx, len1       ;massage length
    int 0x80            ;core call

outprog:
    mov eax, 1          ;system call number (sys_exit)
    int 0x80            ;core call

section .data
even_msg db 'Even number!'  ;the massage with even number
len1 equ $ - even_msg

odd_msg db 'Odd Number!'    ;the massage with odd number
len2 equ $ - odd_msg





















