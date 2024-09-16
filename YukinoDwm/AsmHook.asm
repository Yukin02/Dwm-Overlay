EXTERN Present: PROC
EXTERN PresentCall: QWORD

.CODE

AsmLdrpDispatchUserCallTarget PROC

    sub rsp, 100h
    mov [rsp + 00h], rax
    mov [rsp + 08h], rcx
    mov [rsp + 10h], rdx
    mov [rsp + 18h], rbx
    mov [rsp + 20h], rbp
    mov [rsp + 28h], rsi
    mov [rsp + 30h], rdi
    mov [rsp + 38h], r8
    mov [rsp + 40h], r9
    mov [rsp + 48h], r10
    mov [rsp + 50h], r11
    mov [rsp + 58h], r12
    mov [rsp + 60h], r13
    mov [rsp + 68h], r14
    mov [rsp + 70h], r15

    mov rax, [rsp + 100h]   ; return address
    mov rcx, [PresentCall]  ; call __guard_dispatch_icall_fptr + 6

    cmp rax, rcx
    jne JmpOriginal

    mov rcx, rdx            ; SwapChain

    sub rsp, 08h
    call Present
    add rsp, 08h

JmpOriginal:
    mov rax, [rsp + 00h]
    mov rcx, [rsp + 08h]
    mov rdx, [rsp + 10h]
    mov rbx, [rsp + 18h]
    mov rbp, [rsp + 20h]
    mov rsi, [rsp + 28h]
    mov rdi, [rsp + 30h]
    mov r8, [rsp + 38h]
    mov r9, [rsp + 40h]
    mov r10, [rsp + 48h]
    mov r11, [rsp + 50h]
    mov r12, [rsp + 58h]
    mov r13, [rsp + 60h]
    mov r14, [rsp + 68h]
    mov r15, [rsp + 70h]

    add rsp, 100h

    jmp rax
AsmLdrpDispatchUserCallTarget ENDP

END