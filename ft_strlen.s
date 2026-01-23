BITS 64

GLOBAL ft_strlen

ft_strlen:
	xor rax, rax
.ft_strlen_loop:
	cmp [rdi], byte 0x00
	je .ft_strlen_end
	inc rax
	inc rdi
	jmp .ft_strlen_loop
.ft_strlen_end:
	ret
