section .text									;indicate that we are in the text section of memory, which contain all the actual code
global ft_strcmp								;declaring ft_strcmp as global so it is accessible from C code which calls it

ft_strcmp :										;non-local label named ft_strcmp, valid in the whole file
xor			rcx, rcx							;set rcx value to 0 (rcx being the count register, we use it here as itterrator)
.end_string :
cmp			byte [rsi + rcx], 0
je			.return
cmp			byte [rdi + rcx], 0
je			.return
.comp :
mov			rdx, [rsi + rcx]
cmp			[rdi + rcx], rdx
jne			.return
add			rcx, 1
jmp			.end_string
.return :
mov			rax, [rdi + rcx]
mov			rdx, [rsi + rcx]
sub			rax, rdx
ret
