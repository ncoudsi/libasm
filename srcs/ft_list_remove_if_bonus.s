section	.text
extern	free
global	ft_list_remove_if

ft_list_remove_if :
push	rbp
mov		rbp, rsp
mov		rbx, [rdi]
mov		r12, rbx
.args_check :
cmp		rdi, 0
je		.return
cmp		rsi, 0
je		.return
cmp		rdx, 0
je		.return
cmp		rcx, 0
je		.return
.core :
cmp		rbx, 0
je		.return
push	rdi
mov		rdi, [rbx]
push	rsi
push	rdx
push	rcx
push	rbx
call	rdx
pop		rbx
pop		rcx
pop		rdx
pop		rsi
pop		rdi
cmp		eax, 0
je		.free
mov		r12, rbx
mov		rbx, qword [rbx + 8]
jmp		.core
.free :
push	rdi
mov		rdi, qword [rbx]
push	rsi
push	rdx
push	rcx
push	rbx
call	rcx
pop		rbx
pop		rcx
pop		rdx
pop		rsi
pop		rdi
mov		r13, qword [r12 + 8]
mov		r13, qword [rbx + 8]
mov		r12, rbx
mov		rbx, qword [rbx + 8]
cmp		r12, [rdi]
jne		.skip
mov		[rdi], rbx
.skip :
push	rdi
mov		rdi, r12
push	rsi
push	rdx
push	rcx
push	rbx
call	free
pop		rbx
pop		rcx
pop		rdx
pop		rsi
pop		rdi
jmp		.core
.return :
pop		rbp
ret