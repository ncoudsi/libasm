section	.text
global	ft_list_sort

ft_list_sort :
push	rbp
mov		rbp, rsp
.args_check :
cmp		rdi, 0
je		.return
cmp		qword [rdi], 0
je		.return
cmp		rsi, 0
je		.return
.init :
mov		rbx, [rdi]
mov		r8 ,rdi
.comp :
push	r8
cmp		qword [rbx + 8], 0
je		.return
push	rdi
push	rsi
mov		rdx, rsi
mov		rcx, [rbx + 8]
mov		rdi, [rbx]
mov		rsi, [rcx]
push	rdx
push	rcx
call	rdx
pop		rcx
pop		rdx
pop		rsi
pop		rdi
cmp		rax, 0
jle		.next_node
push	qword [rbx]
push	qword [rcx]
pop		qword [rbx]
pop		qword [rcx]
pop		r8
mov		rbx, [r8]
jmp		.comp
.next_node :
pop		r8
mov		rbx, [rbx + 8]
jmp		.comp
.return :
pop r8
pop rbp
ret