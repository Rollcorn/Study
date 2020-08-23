section .text
    global _start ;for linker

_start: ;start point for linker
    mov edx,len     ;string lenght
    mov ecx,msg     ;strinig
    mov ebx,1       ;call discriiptor(sdout)
    mov eax,4       ;system call number (sys_write)
    int 0x80        ;core call
    
    mov eax,1       ;system call number (sys_exit)
    int 0x80        ;core call

section .data
msg db 'Hello, world!', 0xa ;out string content
len equ $ - msg     ;string lenght
