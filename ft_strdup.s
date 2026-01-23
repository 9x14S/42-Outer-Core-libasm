BITS 64

GLOBAL ft_strdup

EXTERN _GLOBAL_OFFSET_TABLE_
EXTERN ft_strlen
EXTERN ft_strcpy
EXTERN malloc 

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
	lea rcx, [rcx+malloc wrt ..got]
	push rsi
	call [rcx]
	pop rsi
	cmp rax, qword 0x00
	je .ft_strdup_end
	mov rdi, rax
	call ft_strcpy
.ft_strdup_end:
	ret
