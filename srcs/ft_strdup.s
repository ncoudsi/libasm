section .text
global ft_strdup

ft_strdup :
push		rbp
mov			rbp, rsp
mov			rdx, rdi
extern		ft_strlen
call		ft_strlen
mov			rcx, rax
add			rcx, 1
mov			rdi, rcx
extern		malloc
call		malloc
mov			rdi, rax
mov			rsi, rdx
extern		ft_strcpy
call		ft_strcpy
pop			rbp
ret