section .text				;indicate that we are in the text section of memory, which contain all the actual code
global ft_strlen			;declaring ft_strlen as global so it is accessible from C code which calls it

ft_strlen :					;non-local label named ft_strlen, valid in the whole file
xor		rcx, rcx			;set rcx value to 0 (rcx is the returned value)
.comp :						;local label named .comp, valid only in ft_strlen scope
cmp		byte [rdi + rcx], 0	;set eax with the value of [rdi + rcx] (str[i])
je		.return				;if check verified, jump to .return label
add		rcx, 1				;else, rcx++
jmp		.comp				;jump to .comp label and check again with the new rax value
.return :					;local label named .return, valid only in ft_strlen scope
mov		rax, rcx			;comment
ret							;return rax value