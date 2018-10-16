bits 64

global first_func, second_func, third_func

first_func:
    push rbp
    mov rbp, rsp
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Two values have been provided,
;  with the first stored in RDI,
;  and the second in RSI. If the 
;  first is greater than the second,
;  set RAX equal to 1, if the second
;  is greater than the first, set
;  RAX equal to -1. If they are
;  both equal, set RAX to 0.
;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .compare_val:
        cmp rdi, rsi
        jl .less       
        je .equal
        mov rax, 1
        jmp .finish
    .less:
        mov rax, -1
        jmp .finish
    .equal:
        mov rax, 0
        jmp .finish
    .finish:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    pop rbp
    ret

second_func:
    push rbp
    mov rbp, rsp
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;   You have been provided with
;  a pointer to the start of an
;  array of numbers in RDI, and
;  the number of elements in the
;  array in RSI. Loop through the
;  array, adding all the numbers
;  together, and store the result
;  in RAX.
;
;  HINT:
;  NASM increments arrays by bytes, not bits
;  - ints are generally 4 bytes in size
;
;  Two ways to increment pointer:
;  1: Add 4 to pointer directly
;  2: Use incrementer and work within reference directly ex. 
;     add reg, [regb + regc*4]
;  Feel free to look this up more!
;  
;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    xor rax, rax
    xor rcx, rcx
    mov rcx, rsi
    sum:
        add ax, [rdi + rcx * 4]
        loop sum
        add ax, [rdi]
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    pop rbp
    ret

third_func:
    push rbp
    mov rbp, rsp
    xor rax, rax
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Find the length of the
;  provided, NULL-terminated 
;  string (a pointer to the 
;  beginning of which is 
;  currently stored in RDI),
;  and store the result in RAX.
;
;  BEGIN student code
;
;  HINT: 
;  Just like with second_func, except now we are dealing with chars
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    xor rax, rax
    xor cl, cl
    .start:
        cmp cl, [rdi + rax]
        je .finish

        inc rax
        jmp .start
    .finish:  
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    pop rbp
    ret


