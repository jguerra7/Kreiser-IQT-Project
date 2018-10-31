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
    xor rax, rax				;zero out rax
    mov rdx, 0xfffffffffffff	;set rdx to super high number
    mov rcx, rdx				;set rcx to high number

    repne scasb					;repeat until null
    sub rdx, rcx				;calculate offset

    dec rdx						;decrement rdx
    mov rax, rdx				;store rdx in our return value
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
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
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
	xor rax, rax		;zero out rax
	xor rcx, rcx		;zero out rcx

    mov     rcx, rdx 	; size_t num
    mov     rax, rsi	;move the value into rax
    rep     stosb		;repeat storing bytes in buffer
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
	mov rcx, rdx	;move length into srcx

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
    


ex_strstr:	;extern "C" char* ex_strstr(char*, char*);
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;rdi : Full string buffer to search for substring
	;rsi :  to look for
	;Shout out to ELF for the solution
	push rbp
	mov rbp, rsp

.setUp:
    mov rbx, rdi                    ;storing the location of the beginning of rdi
.getLengthNeedle:
    mov rdi, rsi        
    call ex_strlen                  ;get length of needle and store it in rcx
    mov r9, rax                     ;stores needle length into r9 
.getLengthHaystack:
    mov rdi, rbx                    ;move the haystack back into rdi
    call ex_strlen                  ;gets the length of the haystack
    mov rcx, rax                    ;moves the length of the haystack into rcx
.findFirst:                         ;scans haystack for the first character of the needle
    mov rdi, rbx                    ;make sure were at the right spot in the haystack
    movzx rax, byte [rsi]           ;moves the first character of the needle into rax
    repne scasb                     ;scans the haystack for the first character
    jne .notfound                    ;end if we have reached the end of the haystack
    sub rdi, 1                      ;string instructions always go one past so we need to go back one
    mov rbx, rdi                    ;since we have found the first chr of the needle lets preserve this location

.compareNeedle:                     ;Checks to see if the next (needle len) characters of the haystack are = to the needle
    mov rcx, r9                     ;move the length of the needle from r9
    push rsi                        ;preserve the location of the needle
    rep cmpsb                       ;compare needle length times
    je .found                       ;if the two strings are = to this point then yay we found it
    pop rsi                         ;start back at the beginning of the needle
    add rbx, 1                      ;increment past the character we found 
    jmp .getLengthHaystack          ;if they are not equal then go back to looking for the first charcter again

.notfound:
    xor rax, rax
    jmp .end

.found:
    pop rsi                         ;start back at the beginning of the needle
    mov rax, rbx                    ;move the location of the haystack before we found the string (right at the beginning)

.end:
    pop rbp
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

;Shout out to ELF for the solution
push rbp
mov rbp, rsp

.setup:
	xor rcx, rcx
	mov rcx, 1                  ;rcx = j
	xor rbx, rbx                ;rbx = i = 0
	xor rax, rax                ;rax = key = 0
	xor edx, edx
cmp rdi, 0                      ;check if the array is empty
je .end
cmp rsi, 0                      ;check if the size is 0
je .end
.outterLoop:
	cmp rcx, rsi                ;compares j to size if j>size then were done
	je .end                     ;if j > size end
	mov rbx, rcx                ;i=j-1
	sub rbx, 1
	lea rax, [rdi + rcx*4]
	mov eax, dword [rax]

	.innerLoop:
		cmp rbx, -1                         ;if i <0 then iterate to next j value
		je .backToOuter          
		cmp [rdi + rbx*4], eax              ;if array[i] > key iterate to next i value
		jb .backToInner  
		lea rdx, [rdi + rbx*4]              ;edx = *array[i]
		mov edx, dword [rdx]                ;edx = array[i]
		xchg edx, [rdi + rbx*4 + 4]         ;array[i+1]<-->r10
		xchg edx, [rdi + rbx*4]             ;array[i]<-->r10
		jmp .backToInner 

.backToOuter:
	add rcx, 1                          ;j+1
	jmp .outterLoop

.backToInner:
	sub rbx, 1                          ;i+1
	jmp .innerLoop

.end:
	mov rax, rdi
	pop rbp
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  END student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret


ex_qsort:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  BEGIN student code
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;This function produced by Miguel Casillas

	;This registers must be stored until the end
; 	push rbp
; 	mov rbp, rsp
; 	push rbx
; 	push rsi
; 	push rdi

; 	;EBP + 8 is the array
; 	;EBP + 12 is the number of items in the array

; 	mov esi, [rbp+ 8]

; 	;setting ecx to the number of items
; 	;we multiply y 4 (size of the element) in order to put ecx
; 	;at the last address of the array

; 	mov eax, [rbp+12]
; 	mov ecx, 4
; 	mul ecx
; 	mov ecx, eax

; 	;eax will be our 'low index', we initially set it to 0
; 	xor eax, eax

; 	;ebx will be our 'high index', we initally set it to
; 	;the last element of the array (currently stored in ecx)
; 	mov ebx, ecx

; 	;We now call our recursive quicksort function that will sort the array
; 	call quickRecursive

; 	;restoring the registers
; 	pop rdi
; 	pop rsi
; 	pop rbx
; 	pop rbp

; quickRecursive:
; 	;If lowIndex >= highIndex, we exit the function
; 	cmp eax, ebx
; 	jge postIf

; 	push rax	;saving our low index, now eax is 'i'
; 	push rbx	;saving our high index, now ebx is 'j'
; 	add ebx, 4	;j = high + 1

; 	;edi is our pivot
; 	;pivot = array[lowIndex];
; 	mov edi, [esi+eax]

; 	mainLoop:

; 		iIncreaseLoop:

; 			;i++
; 			add eax, 4

; 			;If i >= j, exit this loop
;             cmp eax, ebx
;             jge End_iIncreaseLoop
           
;             ;If array[i] >= pivot, exit this loop
;             cmp [esi+eax], edi
;             jge End_iIncreaseLoop
           
;             ;Go back to the top of this loop
;             jmp iIncreaseLoop

;         End_iIncreaseLoop:
       
;         jDecreaseLoop:
       
;             ;j--
;             sub ebx, 4
           
;             ;If array[j] <= pivot, exit this loop
;             cmp [esi+ebx], edi
;             jle End_jDecreaseLoop
           
;             ;Go back to the top of this loop
;             jmp jDecreaseLoop

;         End_jDecreaseLoop:
       
;         ;If i >= j, then don't swap and end the main loop
;         cmp eax, ebx
;         jge EndMainLoop
       
;         ;Else, swap array[i] with array [j]
;         push [rsi+rax]
;         push [rsi+rbx]
       
;         pop [rsi+rax]
;         pop [rsi+rbx]
       
;         ;Go back to the top of the main loop
;         jmp mainLoop
       
;     EndMainLoop:       
   
;     ;Restore the high index into EDI
;     pop rdi
   
;     ;Restore the low index into ECX
;     pop rcx
   
;     ;If low index == j, don't swap
;     cmp ecx, ebx
;     je EndSwap
   
;     ;Else, swap array[low index] with array[j]
;     push [rsi+rcx]
;     push [rsi+rbx]
       
;     pop [rsi+rcx]
;     pop [rsi+rbx]
       
;     EndSwap:

;     ;Setting EAX back to the low index
;     mov eax, ecx
   
;     push rdi    ;Saving the high Index
;     push rbx    ;Saving j
   
;     sub ebx, 4  ;Setting EBX to j-1
   
;     ;QuickSort(array, low index, j-1)
;     call quickRecursive
   
;     ;Restore 'j' into EAX
;     pop rax
;     add eax, 4  ;setting EAX to j+1
   
;     ;Restore the high index into EBX
;     pop rbx
   
;     ;QuickSort(array, j+1, high index)
;     call quickRecursive
   
;     postIf: 
; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; ;  END student code
; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;     ret
