section .data
    message db 'Hello, Holberton', 10 ; the message to be printed followed by a newline character
    length equ $-message ; length of the message

section .text
    global main
    extern printf ; declare the printf function as an external symbol

    ; set up stack frame
    main:
        push rbp
        mov rbp, rsp

        ; call printf with the message as argument
        mov edi, message
        xor eax, eax
        call printf

        ; clean up stack and exit
        mov rsp, rbp
        pop rbp
        xor eax, eax
        ret

