bits 32

global _copy_string, _get_cpu_string@4, _set_flags

section .text


_copy_string:
;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;	This method takes 3 params:
;
;	Param 1: An empty buffer
;
;	Param 2: A NULL-terminated string
;
;	Given these two inputs, 
;	1.) Find the length of the string provided in
;	param 2
;	2.) Copy the string from param 2, to the empty buffer
;	provided in param 1.
;
;	void __cdecl _copy_string(char* dest, char* src);
;
; BEGIN STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;
	
	xor eax, eax
	mov edi, [esp + 4]					;set param1
	mov ecx, [esp + 8]					;set param2

	.strlen:							;loop to get string length
					
		xor edx, edx					;Zero edx
		mov dl, byte [ecx + eax]		;set dl equal to ecx plus eax
		inc eax							;increment eax by 1 to keep count of characters
		cmp dl, 0
		jne .strlen						;loop until strlen found
		mov ecx, eax					;move the strlen to ecx for copying the string
		add ecx, 1						;Don't forget the null terminator

	.next:
		mov esi, [esp + 8]
		rep movsb
		mov eax, edi

	ret
;;;;;;;;;;;;;;;;;;;;;;;;;;
; END STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;

_get_cpu_string@4:
;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;	This function takes 1 param:
;
;	Param 1: A zero'd character buffer, containing
;	13 elements.
;
;	The following steps must be performed:
;	1.) Call CPUID and get the vendor string
;	2.) Copy from ASCII bytes returned into the buffer
;	provided.
;	
;	void __stdcall _get_cpu_string(char* buf);
;
;
; BEGIN STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;
	xor eax, eax		;Zero eax
	mov edi, [esp + 4]	;Create a buffer for output
	cpuid				;Uses ebx, edx, ecx in this order
	
	mov eax, ebx	;Move first output register into eax
	stosd			;Store eax into edi

	mov eax, edx	;Move second output register into eax
	stosd			;Store eax into edi

	mov eax, ecx	;Move third output register into eax
	stosd

	ret 4
;;;;;;;;;;;;;;;;;;;;;;;;;;
; END STUDENT CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;