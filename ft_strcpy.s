BITS 64

GLOBAL ft_strcpy

SECTION .text

ft_strcpy:
	xor rax, rax
.ft_strcpy_loop:
.ft_strcpy_copy_byte:
	movzx rcx, byte [rsi + rax]
	mov byte [rdi + rax], cl

.ft_strcpy_exit_on_null:
	cmp byte [rsi + rax], byte 0x00
	jz .ft_strcpy_end

	inc rax
	jmp .ft_strcpy_loop
.ft_strcpy_end:
	mov [rdi + rax], byte 0x00
	mov rax, rdi
	ret
