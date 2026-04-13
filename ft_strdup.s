BITS 64

%define ENOMEM 12

GLOBAL ft_strdup

EXTERN _GLOBAL_OFFSET_TABLE_
EXTERN ft_strlen
EXTERN ft_strcpy
EXTERN malloc 
EXTERN __errno_location

SECTION .text

ft_strdup:
	call .ft_strdup_get_GOT
.ft_strdup_get_GOT:
	pop rcx
	add rcx, _GLOBAL_OFFSET_TABLE_+$$-.ft_strdup_get_GOT wrt ..gotpc
.ft_strdup_get_malloc:
	push rcx
	lea rcx, [rcx+malloc wrt ..got]
.ft_strdup_get_length:
	push rdi
	call ft_strlen
	inc rax			; +1 for null byte
.ft_strdup_alloc:
	mov rdi, rax
	call [rcx]		; Call malloc
	pop rsi
	pop rcx
.ft_strdup_exit_on_nomem:
	cmp rax, qword 0x00
	je .ft_strdup_ENOMEM
.ft_strdup_copy_to_buffer:
	mov rdi, rax
	call ft_strcpy
	jmp .ft_strdup_end
.ft_strdup_ENOMEM:
	lea rcx, [rcx+__errno_location wrt ..got]
	call [rcx]
	mov [rax], dword ENOMEM
	xor rax, rax
.ft_strdup_end:
	ret
