section	.text
extern	malloc
global	ft_list_push_front

ft_list_push_front :
push	rbp
mov		rbp, rsp
push	rdi
push	rsi
mov		rdi, 16
call	malloc
pop		rsi
pop		rdi
mov		qword [rax], rsi
mov		rdx, [rdi]
mov		[rax + 8], rdx
mov		[rdi], rax
pop		rbp
ret