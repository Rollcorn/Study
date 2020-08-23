section .text
    global _start   ;for linker (gcc)
    
_start:             ;enter point for linker
    mov edx,len     ;string length
    mov ecx,msg     ;massage for writing
    mov ebx,1       ;file descriptor (stdout)
    mov eax,4       ;system call number (sys_write)
    int 0x80        ;core call
    
    mov edx,9       ;massage length
    mov ecx,s2      ;massage for writing
    mov ebx,1       ;file descriptor(stdout)
    mov eax,4       ;system call number (sys_write)
    int 0x80        ;core call
    
    mov eax,1       ;system call number (sys_exit)
    int 0x80        ;core call
    
section .data
msg db 'Displaying 9 stars', 0xa ;our massage
len equ $ - msg     ;our massage length
s2 times 9 db '*'

