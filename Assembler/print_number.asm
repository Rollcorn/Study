section .data                           ;Data segment!
    userMsg db 'Please enter a number: ';Massage ask to enter number
    lenUserMsg equ $-userMsg            ;Massage length
    dispMsg db 'you have entered: '
    lenDispMsg equ $-dispMsg

section .bss        ;not initialized data!
    num resb 5

section .txt        ;code segment!
    global _start

_start:             ;ask user code
    mov eax, 4
    mov ebx, 1
    mov ecx, userMsg
    mov edx, lenUserMsg
    int 80h

    ;Read and save users enter
    mov eax, 3
    mov ebx, 2
    mov ecx, num
    mov edx, 5      ;5 bite informations
    int 80h

    ;Output massage 'The entered number is: '
    mov eax, 4
    mov ebx, 1
    mov ecx, num
    mov edx,5
    int 80h

    ;Exit code
    mov eax, 1
    mov ebx, 0
    int 80h
