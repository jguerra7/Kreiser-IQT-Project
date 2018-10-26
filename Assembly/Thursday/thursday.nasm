bits 32

global _fibonacci@4, _walk_list_map@8


section .text


_fibonacci@4:
;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;	This method takes a single parameter:
;	
;	Param 1: The fibonacci number to calculate (e.g., "5" would indicate
;	to calculate and return the 5th fibonacci number).
;
;	int __stdcall fibonacci(int n);	
;
; BEGIN STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;
	xor eax, eax ;next
    xor ecx, ecx
    xor edx, edx ;first
    mov esi, 1 ;second
	mov edi, [esp + 4]
    dec edi


    .continue:
        mov eax, edx ;next = first
        add eax, esi ;next += second
        mov edx, esi ;first = second
        mov esi, eax ;second = next
        inc ecx ;i++
        cmp ecx, edi ; i < N
        jb .continue
	ret 4
;;;;;;;;;;;;;;;;;;;;;;;;;;
; END STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;


struc Node
	.Next	resd  1
	.Data	resd  1
endstruc


_walk_list_map@8:
;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;	This method takes two parameters:
;
;	Param 1: A pointer to the beginning of a linked list of nodes (structure
;	definition above)
;
;	Param 2: A function pointer
;
;	Your task:
;	1.) Walk the list of nodes
;	2.) For each node, call the function pointer provided
;	as parameter 2, giving it as input the Data from the node.
;
;	void __stdcall walk_list_map(Node* n, void(*)(size_t));
;
; BEGIN STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;
	;rdi : linked list of nodes
	;rsi : function pointer
	mov esi, [esp + 4]	; List of nodes
	mov edi, [esp + 8]	; Function pointer
	
	
	.continue:
		xor eax, eax
		mov eax, [esi + Node.Data]		;set eax equal to edi's node data
		push eax						;preserve eax
		call edi						;call function pointer
		pop eax							;bring eax back
		mov esi, [esi + Node.Next]		;move to next node
		cmp esi, 0						;check for null terminator

		je .end							;Null terminator located	
		jmp .continue					;jump to continue if null terminator isn't found
	.end:
	ret 8
;;;;;;;;;;;;;;;;;;;;;;;;;;
; END STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;