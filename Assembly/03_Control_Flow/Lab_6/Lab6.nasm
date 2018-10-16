; Name: William Kreiser
; Date: 15 Oct 18
; Project: Lab6

bits 64

global first_func, second_func, third_func

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; INSTRUCTIONS
; -Set the flags via by arithmetic operation
; -Then set the flags manually*
; *You will need to comment out the previous solution 


first_func:
    push rbp
    mov rbp, rsp
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Set the carry flag.
;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    or rax, rax
    pushf
    mov rax, 1
    push rax
    popf
    pop rax
    ;mov al, -5 ;This works for all 3 functions
    ;add al, 132  
    ;xor eax, eax 
    ;sub eax, 1 
    ; stc ; setting the carry flag manually
    ; clc ; clear the carry flag
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    pop rbp
    ret

second_func:
    push rbp
    mov rbp, rsp
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Set the overflow flag.
;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    pushf
    mov ax, 2048
    ; mov rax, bits [11] 
    push ax
    popf
    pop ax
    ; mov al, -5 ;This works for all 3 functions
    ; add al, 132
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    pop rbp
    ret

third_func:
    push rbp
    mov rbp, rsp
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Set both the carry and overflow
;  flags.
;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    pushf
    mov ax, 2048 
    mov ax, 1
    ; mov rax, bits [11] 
    push ax
    popf
    pop ax
    ; mov al, -5 ;This works for all 3 functions
    ; add al, 132
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    pop rbp
    ret