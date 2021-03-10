section .text
extern		ft_strlen
extern		malloc
extern		ft_strcpy
global ft_strdup


ft_strdup :
push		rbp
mov			rbp, rsp
mov			rdx, rdi
call		ft_strlen
mov			rcx, rax
add			rcx, 1
mov			rdi, rcx
push		rcx
push		rdx
call		malloc
pop			rdx
pop			rcx
sub			rcx, 1
mov			byte [rax + rcx], 0
mov			rdi, rax
mov			rsi, rdx
call		ft_strcpy
pop			rbp
ret