section .text		;indicate that we are in the text section of memory, which contain all the actual code
global ft_write		;declaring ft_write as global so it is accessible from C code which calls it

ft_write :			;non-local label named ft_write, valid in the whole file
mov	rax, 1			;move 1 value in rax, that is the system call number for write
syscall				;call the system call depending on rax value (rsi, rdi and rdx will be set accordingly)
ret					;return rax value (being the returned value of write)
					;see : https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
					;for syscall list.