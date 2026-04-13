BITS 64

GLOBAL ft_strcmp

SECTION .text

ft_strcmp:
.ft_strcmp_loop:
	cmp [rdi], byte 0x00
	je .ft_strcmp_end
	cmp [rsi], byte 0x00
	je .ft_strcmp_end
	mov cl, byte[rsi]
	cmp [rdi], cl
	jne .ft_strcmp_end

	inc rdi
	inc rsi
	jmp .ft_strcmp_loop
.ft_strcmp_end:
	movzx eax, byte [rdi]
	movzx ecx, byte [rsi]
	sub eax, ecx
	ret
