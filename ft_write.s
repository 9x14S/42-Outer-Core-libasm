BITS 64

GLOBAL ft_write

EXTERN _GLOBAL_OFFSET_TABLE_
EXTERN __errno_location

SECTION .text

ft_write:
	mov eax, 1
	syscall
	cmp rax, 0x00
	jl .ft_write_set_errno
	jmp .ft_write_end
.ft_write_set_errno:
	call .ft_write_get_GOT
.ft_write_get_GOT:
	pop rdx
	add rdx, _GLOBAL_OFFSET_TABLE_+$$-.ft_write_get_GOT wrt ..gotpc
	lea rdx, [rdx+__errno_location wrt ..got]
	push rax
	call [rdx]
	mov rdx, rax
	pop rax
	xor rcx, rcx
	sub rcx, rax
	mov [rdx], dword ecx
	mov rax, -1
.ft_write_end:
	ret
