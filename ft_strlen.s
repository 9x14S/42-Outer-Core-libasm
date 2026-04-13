BITS 64

GLOBAL ft_strlen

SECTION .text

ft_strlen:
	xor rax, rax
.ft_strlen_loop:
	cmp byte [rdi], byte 0x00
	jz .ft_strlen_end
	inc rax
	inc rdi
	jmp .ft_strlen_loop
.ft_strlen_end:
	ret
