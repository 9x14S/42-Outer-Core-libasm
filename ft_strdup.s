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
.ft_strdup_alloc:
	mov rsi, rdi
	call ft_strlen
	inc rax
	mov rdi, rax
	push rcx
	lea rcx, [rcx+malloc wrt ..got]
	push rsi
	call [rcx]
	pop rsi
	pop rcx
	cmp rax, qword 0x00
	je .ft_strdup_ENOMEM
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
