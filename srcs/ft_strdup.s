section .text						;indicate that we are in the text section of memory, which contain all the actual code
extern		malloc					;declaring malloc as an extern so we can call it from this file
extern		ft_strlen				;declaring ft_strlen as an extern so we can call it from this file
extern		ft_strcpy				;declaring ft_strcpy as an extern so we can call it from this file
global ft_strdup					;declaring ft_strdup as global so it is accessible throughout all the file

ft_strdup :							;non-local label named ft_strdup, valid in the whole file
push		rbp						;put rbp value on top of the stack
mov			rbp, rsp				;move rsp value in rbp (they both are pointers so now the are pointing the same address)
									;for more intels regarding stack management, see (in french only) https://beta.hackndo.com/stack-introduction/
mov			rdx, rdi				;move rdi value in rdx
push		rdx						;push rdx value on top of the stack
call		ft_strlen				;call ft_strlen
pop			rdx						;move the value on top of the stack in rdx (and remove it from the top of the stack)
mov			rcx, rax				;move rax value (return value of ft_strlen) in rcx
add			rcx, 1					;add 1 to rcx value
mov			rdi, rcx				;move rcx value to rdi
push		rcx						;push rcx value on top of the stack
push		rdx						;push rdx value on top of the stack
call		malloc					;call malloc
pop			rdx						;move the value on top of the stack in rdx (and remove it from the top of the stack)
pop			rcx						;move the value on top of the stack in rcx (and remove it from the top of the stack)
sub			rcx, 1					;substract 1 to rcx value
mov			byte [rax + rcx], 0		;move 0 to [rax + rcx] (str[i] = '\0' where str + i points to the end of str string)
mov			rdi, rax				;move rax value to rdi
mov			rsi, rdx				;move rdx value to rsi
call		ft_strcpy				;call ft_strcpy
pop			rbp						;move the value on top of the stack in rbp (and remove it from the top of the stack)
ret									;return rax value