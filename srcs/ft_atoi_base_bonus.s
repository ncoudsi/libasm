section	.text
extern	is_valid_base
extern	is_whitespace
extern	is_base
extern	ft_strlen
global	ft_atoi_base

ft_atoi_base :
push	rbp
mov		rbp, rsp
mov		r12, 0
mov		r13, 1
mov		r14, -1
push	rsi
push	rdi
mov		rdi, rsi
call	is_valid_base
pop		rdi
pop		rsi
cmp		eax, 0
je		.return
mov		rcx, 0
mov		rdx, rsi
.white_spaces :
push	rsi
push	rdi
movzx	rsi, byte [rdx + rcx]
call	is_whitespace
pop		rdi
pop		rsi
add		rcx, 1
cmp		eax, 1
je		.white_spaces
.plus :
cmp		byte [rdx + rcx], 43
je		.next_sign
.minus :
cmp		byte [rdx + rcx], 45
jne		.fill_str
mov		rax, r13
imul	r14
mov		r13, rax
.next_sign :
add		rcx, 1
jmp		.plus
.fill_str :
add		rcx, 1
push	rdi
push	rsi
movzx	rdi, byte [rdi + rcx]
call	is_base
pop		rsi
pop		rdi
cmp		eax, -1
je		.return
push	rdi
mov		rdi, rsi
call	ft_strlen
pop		rdi
imul	r12
push	rdi
movzx	rdi, byte [rsi]
call	is_base
add		r12, rax
add		rcx, 1
jmp		.fill_str
.return :
mov		rax, r12
imul	r13
pop		rbp
ret