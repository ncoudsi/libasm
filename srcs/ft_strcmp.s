section .text						;indicate that we are in the text section of memory, which contain all the actual code
global ft_strcmp					;declaring ft_strcpy as global so it is accessible throughout all the file

ft_strcmp :							;non-local label named ft_strcmp, valid in the whole file
push		rbp						;put rbp velu on top of the stack
mov			rbp, rsp				;move rsp value in rbp (they bot are pointers so now the are pointing the same address)
									;for more intels regarding stack management, see (in french only) https://beta.hackndo.com/stack-introduction/
xor			rcx, rcx				;set rcx value to 0 (rcx being the count register, we use it here as itterrator)
.end_string :						;local label named .end_string, valid only in ft_strcmp scope
cmp			byte [rsi + rcx], 0		;compare [rsi + rcx] byte value to 0 (if (src[i] == '\0'))
je			.return					;if check verified, jump to .return label
cmp			byte [rdi + rcx], 0		;compare [rdi + rcx] byte value to 0 (if (dest[i] == '\0'))
je			.return					;if check verified, jump to .return label
.comp :								;local label named .comp, valid only in ft_strcmp
mov			rdx, [rsi + rcx]		;move [rsi + rcx] value to rdx (rdx = str[i])
cmp			[rdi + rcx], rdx		;compare rdx value to [rdi + rcx] (if (dest[i] == rdx))
jne			.return					;if check not verified, jump to .return label
add			rcx, 1					;rcx++
jmp			.end_string				;jump to .end_string label
.return :							;local label named .return, valid only in ft_strcmp scope
mov			r8b, byte [rdi + rcx]	;move [rdi + rcx] value to r8b (r8b = dest[i])
mov			r9b, byte [rsi + rcx]	;move [rsi + rcx] value to r9b (r9b = src[i])
sub			r8b, r9b				;substract rxd to r8b (r8b -= r9b)
cmp			r8b, 0					;compare rax value to 0
jl			.negative				;if rax is lower than 0, jump to .negative local label
je			.equal					;else if rax is equal to 0, jump to .equal local label
jmp			.positive				;else jump to .positive local label
.negative :							;local label named .negative, valid only in ft_strcmp scope
mov			rax, -1					;move -1 to rax value
pop			rbp						;move the value on top of the stack in rbp (and remove it from the top of the stack)
ret									;return rax value
.equal :							;local label named . equal, valid only in ft_strcmp scope
mov			rax, 0					;move 0 to rax valu
pop			rbp						;move the value on top of the stack in rbp (and remove it from the top of the stack)
ret									;return rax value
.positive :							;local label named .positive, valid only in ft_strcmp scope
mov			rax, 1					;move 1 to rax value
pop			rbp						;move the value on top of the stack in rbp (and remove it from the top of the stack)
ret									;return rax value