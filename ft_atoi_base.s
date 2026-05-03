BITS 64

%define CHECK_ARRAY 0x100
%define ORDER_ARRAY 0x100

%define STACK_SIZE CHECK_ARRAY + ORDER_ARRAY

SECTION .text

GLOBAL ft_atoi_base

ft_atoi_base:
  sub rsp, STACK_SIZE ; Stack allocation for char mapping (don't save EBP)
  xor eax, eax
  test rdi, rdi  ; Test str != NULL
  jz .return     ; Don't jump to .error since eax is zero anyways
  test rsi, rsi  ; Test base != NULL
  jz .return     ; Don't jump to .error since eax is zero anyways

.zero_char_map:
  xor rcx, rcx
.zero_loop:
  cmp rcx, STACK_SIZE     ; Could have iterated using 64-bit writes, but I'm lazy
  je .fill_forbidden_chars
  mov byte [rsp], 0
  inc rcx
  jmp .zero_loop

.fill_forbidden_chars:
  inc byte [rsp+'+']
  inc byte [rsp+'-']

  inc byte [rsp+' ']
  inc byte [rsp+'\r']
  inc byte [rsp+'\f']
  inc byte [rsp+'\v']
  inc byte [rsp+'\n']
  inc byte [rsp+'\t']
.fill_char_map:
  xor rcx, rcx           ; Iterate over base
.fill_loop:
  cmp byte [rsi+rcx], 0
  je .parse_number
  xor rdx, rdx
  mov dl, byte [rsi+rcx] ; Get char
  lea rdx, [rsp+rdx]     ; Use it to index into array of zeroes
  inc byte [rdx]         ; Mark as seen
  cmp byte [rdx], 1      ; Has been seen more than once?
  jg .error              ; Duplicate char, error
.fill_order:
  mov r8, rcx
  add r8, ORDER_ARRAY
  mov byte [rsp+r8], dl  ; Index into ordering array
  inc rcx
  jmp .fill_loop

.parse_number:
  cmp rcx, 2
  jl .return                ; Base is less than 2 characters long
  mov rdx, rcx              ; Save length of base
  xor rcx, rcx              ; Iterate over str
.parse_loop:
  cmp byte [rdi+rcx], 0
  je .return                ; Done, no errors
  mul eax, edx              ; acc *= 10
  xor r8d, r8d
  movzx r8d, byte [rdi+rcx] ; str[i]
  mov r10, rsp
  add r10, ORDER_ARRAY
  movzx r8d, byte [r10+r8]  ; position = order[str[i]]
  add eax, r8d              ; acc += position
  inc rcx                   ; i++
  jmp .parse_loop

.error:
  xor eax, eax
.return:
  add rsp, STACK_SIZE
  ret
