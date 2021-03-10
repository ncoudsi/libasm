section .text						;indicate that we are in the text section of memory, which contain all the actual code
global ft_strcpy					;declaring ft_strcpy as global so it is accessible throughout all the file

ft_strcpy :							;non-local label named ft_strcpy, valid in the whole file
push		rbp						;put rbp on top of the stack
mov			rbp, rsp				;move rsp value in rbp (they bot are pointers so now the are pointing the same address)
									;for more intels regarding stack management, see (in french only) https://beta.hackndo.com/stack-introduction/
xor			rcx, rcx				;set rcx value to 0 (rcx being the count register, we use it here as itterrator)
cmp			byte [rsi + rcx], 0		;compare [rsi + rcx] byte value to 0 (if (src[i] == '\0'))
je			.exception				;if check verified, jump to .exception label
.comp :								;local label named .comp, valid only in ft_strcpy scope
cmp			byte [rsi + rcx], 0		;compare [rsi + rcx] byte value to 0 (if (src[i] == '\0'))
je			.return					;if check verified, jump to .return label
mov			rdx, [rsi + rcx]		;else, set rdx value with [rsi + rcx] value (tmp = src[i])
mov			[rdi + rcx], rdx		;set [rdi + rcx] value with rdx value (dst[i] = tmp)
add			rcx, 1					;rcx++
jmp			.comp					;jump to .comp label and check again with the new rcx value
.return :							;local label named .return, valid only in ft_strcpy scope
mov			byte [rdi + rcx], 0		;move 0 to [rdi + rcx] (dst[i] = '\0')
mov			rax, rdi				;move rdi value in rax, since rax is the returned value
pop			rbp						;move the value on top of the stack in rbp (and remove it from the top of the stack)
ret									;return rax value
.exception :						;local label named .exception, valid only in ft_strcpy scope
mov			byte [rdi + rcx], 0		;move 0 to [rdi + rcx] (dst[i] = '\0')
mov			rax, rdi				;set rax value to rdi
pop			rbp						;move the value on top of the stack in rbp (and remove it from the top of the stack)
ret									;return rax value