section	.text
global	ft_list_size

ft_list_size :
push	rbp
mov		rbp, rsp
xor		rcx, rcx
cmp		rdi, 0
je		.return
add		rcx, 1
mov		rdx, rdi
.comp :
cmp		qword [rdx + 8], 0
je		.return
add		rcx, 1
mov		rdx, [rdx + 8]
jmp		.comp
.return :
mov		rax, rcx
pop		rbp
ret