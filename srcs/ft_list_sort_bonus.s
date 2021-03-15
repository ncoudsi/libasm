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
cmp		qword [rbx + 8], 0
je		.return
push	rdi
push	rsi
mov		rdx, rsi
mov		rdi, [rbx]
mov		rcx, [rbx + 8]
mov		rsi, [rcx]
push	rdx
push	rcx
call	rdx
pop		rcx
pop		rdx
pop		rsi
pop		rdi
cmp		rax, 0
jbe		.next_node
push	qword [rbx]
push	qword [rcx]
pop		qword [rbx]
pop		qword [rcx]
mov		rbx, [r8]
jmp		.comp
.next_node :
mov		rbx, [rbx + 8]
jmp		.comp
.return :
pop rbp
ret