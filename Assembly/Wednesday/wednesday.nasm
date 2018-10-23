; Name: William Kreiser
; Date: 23 Oct 18
; Project: Wednesday lab

bits 32

global _sum_array@8, _find_largest

section .text


_sum_array@8:
;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;	This method takes two parameters:
;
;	Param 1: A pointer to a buffer of integers (4 bytes/each).
;
;	Param 2: A number indicating the number of elements in the buffer.
;
;	You must:
;	1.) Walk through the buffer, and sum together all of the elements
;	2.) Return the result
;
;	int __stdcall sum_array(int* buffer, int size);
;
; BEGIN STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;
	push ebp
	mov ebp, esp
	xor eax, eax

	mov edi, [ebp + 8]		;Buffer of ints
	mov ecx, [ebp + 12]		;Number of elements
		
	.continue:
		add eax, [edi]
		add edi, 4
		loop .continue

	pop ebp
	ret 8
;;;;;;;;;;;;;;;;;;;;;;;;;;
; END STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;


_find_largest:
;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;	This function takes two
;	parameters:
;
;	Param 1: A pointer to a buffer of integers (4 bytes/each)
;
;	Param 2: A number indicating the number of elements in the
;	buffer.
;
;	Your task is to:
;	1.) Walk through the buffer, locating the largest element
;	2.) Return it as the result.	
;
;	int __cdecl find_largest(unsigned long* buffer, int size)
;
; BEGIN STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;

	push ebp
	mov ebp, esp

	mov edi, [ebp + 8]		;edi now contains the buffer of integers
	mov ecx, [ebp + 12]		;ecx now contains the number of elements in buffer

	xor eax, eax			;Zero eax

	.findbig:
		cmp eax, [edi]		;cmp eax to edi
		jg .great			;jumps to great if eax is greater than edi
		mov eax, [edi]

	.great
		add edi, 4			;Move to next element
		loop .findbig		;Call the loop again
	
	pop ebp
	ret
;;;;;;;;;;;;;;;;;;;;;;;;;;
; END STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;