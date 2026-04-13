BITS 64

%define ENOMEM 12 ; Not actually used, we return void???

EXTERN _GLOBAL_OFFSET_TABLE_
EXTERN malloc 

STRUC s_list

	.data: resq 1
	.next: resq 1
ENDSTRUC

SECTION .text

GLOBAL ft_list_push_front

ft_list_push_front:
	test rdi, rdi
	je .end             ; Quick NULL check on first arg
	call .get_GOT
.get_GOT:
	pop rcx
	add rcx, _GLOBAL_OFFSET_TABLE_+$$-.get_GOT wrt ..gotpc
.get_malloc:
	lea rcx, [rcx+malloc wrt ..got]
.alloc:
	push rsi
	push rdi
	mov rdi, s_list_size
	call [rcx]
	pop rdi
	pop rsi
	test rax, rax
	je .end              ; Can't really relay that we've failed so...
.initialize_struct:
	mov qword [rax + s_list.data], qword 0
	mov qword [rax + s_list.next], rsi
	cmp qword [rdi], 0
	je .assign           ; No first member logic
.replace_first:
	mov rsi, qword [rdi]
	mov qword [rax + s_list.next], rsi
.assign:
	mov qword [rdi], rax
.end:
	ret
