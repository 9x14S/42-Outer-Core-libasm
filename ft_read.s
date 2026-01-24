BITS 64

GLOBAL ft_read

EXTERN _GLOBAL_OFFSET_TABLE_
EXTERN __errno_location

ft_read:
	mov eax, 0
	syscall
	cmp rax, 0x00
	jl .ft_read_set_errno
	jmp .ft_read_end
.ft_read_set_errno:
	call .ft_read_get_GOT
.ft_read_get_GOT:
	pop rdx
	add rdx, _GLOBAL_OFFSET_TABLE_+$$-.ft_read_get_GOT wrt ..gotpc
	lea rdx, [rdx+__errno_location wrt ..got]
	push rax
	call [rdx]
	mov rdx, rax
	pop rax
	xor rcx, rcx
	sub rcx, rax
	mov [rdx], dword ecx
.ft_read_end:
	ret
