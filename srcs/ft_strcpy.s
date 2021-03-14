section .text						
global ft_strcpy					

ft_strcpy :							
push		rbp						
mov			rbp, rsp				
									
xor			rcx, rcx				
cmp			byte [rsi + rcx], 0		
je			.exception				
.comp :								
cmp			byte [rsi + rcx], 0		
je			.return					
mov			rdx, [rsi + rcx]		
mov			[rdi + rcx], rdx		
add			rcx, 1					
jmp			.comp					
.return :							
mov			byte [rdi + rcx], 0		
mov			rax, rdi				
pop			rbp						
ret									
.exception :						
mov			byte [rdi + rcx], 0		
mov			rax, rdi				
pop			rbp						
ret									