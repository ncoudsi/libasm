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
mov		rbx, [rdi]
mov		rdx, rsi
.sort :
mov		rcx, qword [rbx + 8]
cmp		rcx, 0
je		.return
mov		rdi, [rbx]
mov		rsi, [rcx]
call	rdx
cmp		rax, 0
jbe		.next_node
push	qword [rbx]
push	qword [rcx]
pop		qword [rbx]
pop		qword [rcx]
mov		rbx, [rdi]
jmp		.sort
.next_node :
mov		rbx, qword [rbx + 8]
jmp	.sort
.return :
pop		rbp
ret