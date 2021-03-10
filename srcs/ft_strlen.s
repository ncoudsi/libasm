section .text					;indicate that we are in the text section of memory, which contain all the actual code
global ft_strlen				;declaring ft_strlen as global so it is accessible throughout all the file

ft_strlen :						;non-local label named ft_strlen, valid in the whole file
push		rbp					;put rbp on top of the stack
mov			rbp, rsp			;move rsp value in rbp (they bot are pointers so now the are pointing the same address)
								;for more intels regarding stack management, see (in french only) https://beta.hackndo.com/stack-introduction/xor		rcx, rcx				;set rcx value to 0 (rcx being the count register, we use it here as itterrator)
.comp :							;local label named .comp, valid only in ft_strlen scope
cmp			byte [rdi + rcx], 0	;compare [rdi + rcx]'s byte value to 0 (if (str[i] == '\0'))
je			.return				;if check verified, jump to .return label
add			rcx, 1				;else, rcx++
jmp			.comp				;jump to .comp label and check again with the new rcx value
.return :						;local label named .return, valid only in ft_strlen scope
mov			rax, rcx			;move rcx's value in rax, since rax is the returned value
pop			rbp					;move the value on top of the stack in rbp (and remove it from the top of the stack)
ret								;return rax value