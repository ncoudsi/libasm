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
mov		[rax], rsi
pop		rdi
mov		rdx, [rdi]
mov		[rax + 8], rdx
mov		rcx, rax
mov		rdx, rax
pop		rbp
ret