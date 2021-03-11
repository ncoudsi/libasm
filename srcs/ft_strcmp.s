section .text						;indicate that we are in the text section of memory, which contain all the actual code
global ft_strcmp					;declaring ft_strcpy as global so it is accessible throughout all the file

ft_strcmp :							;non-local label named ft_strcmp, valid in the whole file
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
mov			rax, [rdi + rcx]		;move [rdi + rcx] value to rax (rax = dest[i])
mov			rdx, [rsi + rcx]		;move [rsi + rcx] value to rdx (rdx = src[i])
sub			rax, rdx				;substract rxd to rax (rax -= rdx)
ret									;return rax value
