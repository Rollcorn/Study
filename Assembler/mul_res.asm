section .text
    global _start   ;mast be define fot using gcc

_start:

    mov al, '3'
    sub al, '0'

    mov bl, '2'
    sub bl, '0'
    mul bl
    add al, '0'

    mov [res], al
    mov ecx, msg
    mov edx, len
    mov ebx, 1      ;files descriptor (stout)
    mov eax, 4      ;system call number (sys_write
    int 0x80        ;core call

    mov ecx, res
    mov edx, 1
    mov ebx, 1      ;files descriptor (stdout)
    mov eax, 4      ;system call number (sys_write)
    int 0x80        ;core call
    
    mov eax, 1      ;system call number (sys_exit)
    int 0x80        ;core call

section .data
msg db "The result is: ", 0xA, 0xD
len equ $-msg
segment .bss
res resb 1
