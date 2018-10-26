bits 64

; LABS
global ex_strlen, ex_memcpy, ex_memset, ex_memcmp, ex_memchr, ex_strchr, ex_strcmp, ex_strcpy, ex_atoi
global ex_strstr, find_largest, walk_list

; BONUS LABS
global ex_isort, ex_qsort


find_largest:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  This function takes two arguments:
;  - Arg1: A pointer to an array of integers
;  - Arg2: The number of integers in the array
;
;  Find and return the largest element in the array.
;  
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	
	;mov edi, [ebp + 8]		;edi now contains the buffer of integers
	;mov ecx, [ebp + 12]	;ecx now contains the number of elements in buffer
	mov rcx, rsi
	xor eax, eax			;Zero eax

	.findbig:
		cmp eax, [rdi]		;cmp eax to edi
		jg .great			;jumps to great if eax is greater than edi
		mov eax, [rdi]

	.great:
		add rdi, 4			;Move to next element
		loop .findbig		;Call the loop again

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret

ex_strlen:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  size_t strlen(char*);  
;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    xor rax, rax
    mov rdx, 0xfffffffffffff
    mov rcx, rdx
    repne scasb
    sub rdx, rcx
    dec rdx
    mov rax, rdx
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret

ex_memcpy:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  void memcpy(void* dst, void* src, int count);
;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	; rdi : destination
	; rsi : source
	; rdx : number of bytes to copy
	xor rcx, rcx
	mov rcx, rdx

	rep movsb
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret


ex_memset:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	void memset(void* buf, unsigned char value, size_t length);
;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	; rdi : buffer pointer
	; rsi : some value
	; rdx : length
	xor rax, rax
	xor rcx, rcx

    mov     rcx, rdx 	; size_t num
    mov     rax, rsi	;move the value into rax
    rep     stosb
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret

ex_memchr:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	void* memchr(void* haystack, unsigned char needle, size_t length);
;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;rdi : haystack
	;rsi : needle
	;rdx : number of bytes to search through
	
	xor rax, rax	;Zero rax and rcx
	xor rcx, rcx	
	
	mov rcx, rdx	;Store length in rcx
	mov rax, rsi	;store the needle character to search for

	repne scasb		
	jne .notfound
	lea rax, [rdi - 1]
	jmp .end
	
	.notfound:
		xor rax, rax
	.end:

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret

ex_memcmp:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	int memcmp(void*, void*, size_t length);
;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;rdi : 1st buffer
	;rsi : 2nd buffer
	;rdx : length of buffer

	xor rcx, rcx	;zero rcx
	mov rcx, rdx	;move length into rcx

	cld				;Clear direction flag	
	rep cmpsb		;repeatedly compare rsi and rdi, increment the pointer and update flags
	je .set			;jump if equal to .set and set rax
	jmp .end		;else jump to .end

	.set:
		xor rax, rax
	.end:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret

ex_strchr:	;char *strchr(const char *str, int c)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;rdi = string
	;rsi = search char

	xor rax, rax	;Zero rax
	push rdi		;Preserve string
	mov rax, rdi	;Move string to rax
	call ex_strlen	;Find length of string
	xor rcx, rcx	;zero count register
	mov rcx, rax	;transfer string length
	pop rdi			;Bring string off of stack
	cld				;clear direction flag
	xor rax, rax	;zero rax for next use
	mov rax, rsi
	repne scasb 	;repeat while not equal using scasb
					;scasb is used to compare string byte by byte
	jne .set		;jump if not equal to .set
	mov rax, rdi	;Move rdi into rax
	dec rax			;dec rax by one byte
	jmp .end		;jump to .end
	.set:
		mov rax, 0	;set rax equal to 0
	.end:

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret

ex_strcmp:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	.start:
	xor rax, rax		;Clear out rax
	push rdi			;preserve rdri
	mov rax, rdi		;store rdi in rax
	call ex_strlen		;get length of first string
	xor rcx, rcx		;zero rcx
	mov rcx, rax		;put string length in rcx
	pop rdi				;bring rdi off of stack
	cld					;clear direction flag
	cmp rcx, rcx		;compare rcx
	rep cmpsb			;repeat cmp of string byte
	je .stop			;jmp if equal to 0
	jg .lzero			;jmp if greater than 0
	mov rax, 1			;set rax to 1 because 2nd pointer is greater
	jmp .end			;jmp to end

	.lzero:
		mov rax, -1		;set rax to -1 because 1st pointer is greater
		jmp .end
	
	.stop:	
	mov  rax, [rdi]		;move the value of rdi into rax
    sub  rax, [rsi]		;subtract rsi from rax
	.end:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret

ex_strcpy:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;rdi is destination string
	;rsi is source string
	xor rax, rax		
	xor r8, r8 		;zero out registers for transfers
    mov r8, rdi		;Move rdi into r8 for storage
	xor rdi, rdi	;zero rdi
	mov rdi, rsi	;mov source string into rdi
	call ex_strlen	;get stringlength of rdi
	xor rcx, rcx	;zero rcx
	mov rcx, rax	;move strlen into rcx
	mov rdi, r8		;move stored destination string back into rdi
	cld				;clear direction flag	
	rep movsb		;repeatedly move data from rsi to rdi and increment pointers
	xor rax, rax	;zero out rax
	stosb			;initialize rdi string and increment the pointer
	mov rax, rdi	;set rax equal to rdi for the return
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  |-- |      |--- |    |\     |    |   |   |-------
;  |   |      |    |    | \    |    |   |   |
;  |---- |    |    |    |  \   |    |   |   |_______
;  |     |    |    |    |   \  |    |   |           |
;  |     |    |    |    |    \ |    |   |           |
;  |____ |    |___ |    |     \|    |___|   ________|
;
;
;        |           |------ |   |------ |     |-------
;        |           |       |   |       |     |_______
;        |           |------ |   |-------- |           |
;        |           |       |   |         |           |
;        |_______    |       |   |_________|   ________|
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


ex_atoi:	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;int atoi(const char *str)
	;rdi : string
	atoi:
    	mov rax, 0              ; Set initial total to 0
     
	convert:
		movzx rsi, byte [rdi]   ; Get the current character
		test rsi, rsi           ; Check for \0
		je done
		
		cmp rsi, 48             ; Anything less than 0 is invalid
		jl error
		
		cmp rsi, 57             ; Anything greater than 9 is invalid
		jg error
		
		sub rsi, 48             ; Convert from ASCII to decimal 
		imul rax, 10            ; Multiply total by 10
		add rax, rsi            ; Add current digit to total
		
		inc rdi                 ; Get the address of the next character
		jmp convert

	error:
		mov rax, -1             ; Return -1 on error
	
	done:
		ret                     ; Return total or error code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret


ex_strstr:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  BEGIN student code
;	char *strstr(const char *haystack, const char *needle)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;rdi : Haystack to search through
	;rsi : needle to look for
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret


struc Node
	.Next	resq	1
	.Data	resq	1
endstruc

 walk_list:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	; rdi : list of nodes
	; rsi : needle to search for
	xor rax, rax
	
	.continue:
		mov eax, [edi + Node.Data]		;set eax equal to edi's node data
		cmp esi, eax					;cmp esi to eax
		je .found						;Found the needle jump to end

		mov edi, [edi + Node.Next]		;Move the next node forward in edi
		cmp edi, 0						;Null node check
		je .end							;Null terminator located	
		jmp .continue					;jump to continue if needle isn't found
	.found:
		mov eax, [edi + Node.Data]		;set eax equal to edi data
	.end:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	ret


ex_isort:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  insertion_sort.c is provided
;  to give an example implementation.
;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret


ex_qsort:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret
