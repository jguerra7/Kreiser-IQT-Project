;	Name: William Kreiser
;	Date: 8 Nov 18
;	Project: Assembly Final

bits 32

section .text

global _movememory

; This task is similar to memcopy but with one important exception: it must 
; be able to handle overlapped memory copies (just like memmove). That is to say, it has to be able
; to perform a copy where the source and destination overlap. This means that the copy either needs
; to happen in reverse, or a buffer must be used.
;
; void __cdecl movememory(void* dest, void* src, size_t length)
_movememory:
	push ebp
	mov ebp, esp

	push edi
	push esi
	push ebx

	mov edi, [ebp+0x8]	;dest
	mov esi, [ebp+0xc]	;src
	mov ecx, [ebp+0x10]	;length

	;// code begin //

	; Preserve destination address because we have to return it.
	mov		edx,	ecx	

    ; If dest < src, we can always do a fast pointer-incrementing move.
    ; If dest == src, do nothing.
    cmp     edi,    esi
    je      .done
    jb      .fast

    ; If dest > src and there are no overlapping regions (dest >= src+num), we
    ; can still do a fast pointer-incrementing move.
    mov     ecx,    esi
    add     ecx,    edx
    cmp     edi,    ecx
    jae     .fast

    ; If dest > src and dest < src+num, we have to do a right-to-left move to
    ; preserve overlapping data.
    .slow:

        ; Set the direction flag so copying is right-to-left.
        std

        ; Set the move count register.
        mov     ecx,    edx

        ; Update pointers to the right-hand side (minus one).
        dec     edx
        add     esi,    edx
        add     edi,    edx

        ; Do a byte-by-byte move.
        rep     movsb

        ; Reset the direction flag.
        cld
		jmp .done

    .fast:

        ; Do a byte-by-byte move.
        mov     ecx,    edx
        rep     movsb

    .done:

   	;//  code end  //

	pop edi
	pop esi
	pop ebx

	mov esp, ebp
	pop ebp

	ret