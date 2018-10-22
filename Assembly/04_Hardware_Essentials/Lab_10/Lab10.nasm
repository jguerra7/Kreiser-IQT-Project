; Name: William Kreiser
; Date: 19 Oct 18
; Project: Monday (Windows)

bits 64

global first_func, second_func, third_func

first_func:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;    Using the rdtsc instruction,
;  1.) Obtain the current timestamp
;  2.) Combine the low 32 bits (from RAX)
;     and the high 32 bits (RDX), and
;     return them.
;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    rdtsc           ;64-Bit value returned EDX[First Half], EAX[Second Half]
    shl rdx, 32     ;rdx high bits were cleared by rdtsc, shift left by 32
    or rax, rdx     ; 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret

second_func:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;   Using CPUID, get the vendor
;  string, and copy each chunk
;  returned into the buffer
;  passed to your function.
;  The buffer should be the
;  first (and only) argument.
; 
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    xor rax, rax
    cpuid

    mov eax, ebx
    stosd

    mov eax, edx
    stosd

    mov eax, ecx
    stosd
    ;mov [rdi], ebx
    ;mov [rdi+4], edx
    ;mov [rdi+8], ecx
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret