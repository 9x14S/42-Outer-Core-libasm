BITS 64

STRUC s_list

	.data: resq 1
	.next: resq 1

ENDSTRUC

SECTION .text

GLOBAL ft_list_size

ft_list_size:
	xor rax, rax
.check_null_ptr:
	cmp rax, rdi
	je .end
	inc rax      ; We know here there's at least one
.list_loop:
	cmp qword [rdi + s_list.next], 0
	je .end
	inc rax
	mov rdi, qword [rdi + s_list.next]
	jmp .list_loop
.end:
	ret
