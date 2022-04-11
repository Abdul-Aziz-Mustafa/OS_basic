section .data
        wlcm db "in function B your integer is converted to:- "

section .bss
        strv resb 8

section .text
        global B_function
        extern C_function
B_function:
        push C_function
        mov [strv], rdi

        mov rax, 1
        mov rdi, 1
        mov rsi, wlcm
        mov rdx, 45
        syscall

        mov rax, 1
        mov rdi, 1
        mov rsi, strv
        mov rdx, 8
        syscall

        ret