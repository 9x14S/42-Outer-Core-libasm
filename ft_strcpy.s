BITS 64

GLOBAL ft_strcpy

SECTION .text

ft_strcpy:
	xor rax, rax
.ft_strcpy_loop:
	cmp [rsi + rax], byte 0x00
	je .ft_strcpy_end
	movzx rcx, byte [rsi + rax]
	mov [rdi + rax], cl
	inc rax
	jmp .ft_strcpy_loop
.ft_strcpy_end:
	mov [rdi + rax], byte 0x00
	mov rax, rdi
	ret
