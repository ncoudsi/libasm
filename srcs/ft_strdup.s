section .text					;indicate that we are in the text section of memory, which contain all the actual code
extern		malloc				;declaring malloc as an extern so we can call it from this file
extern		ft_strlen			;declaring ft_strlen as an extern so we can call it from this file
extern		ft_strcpy			;declaring ft_strcpy as an extern so we can call it from this file
global ft_strdup				;declaring ft_strlen as global so it is accessible throughout all the file


ft_strdup :
push		rbp					;put rbp on top of the stack
mov			rbp, rsp			;move rsp value in rbp (they bot are pointers so now the are pointing the same address)
								;for more intels regarding stack management, see (in french only) https://beta.hackndo.com/stack-introduction/mov			rdx, rdi			;
call		ft_strlen			;
mov			rcx, rax			;
add			rcx, 1				;
mov			rdi, rcx			;
push		rcx					;
push		rdx					;
call		malloc				;
pop			rdx					;
pop			rcx					;
sub			rcx, 1				;
mov			byte [rax + rcx], 0	;
mov			rdi, rax			;
mov			rsi, rdx			;
call		ft_strcpy			;
pop			rbp					;move the value on top of the stack in rbp (and remove it from the top of the stack)
ret