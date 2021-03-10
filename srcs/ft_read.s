section .text					;indicate that we are in the text section of memory, which contain all the actual code
extern __errno_location			;declaring __errno_location as an extern so we can call it from this file
global ft_read					;declaring ft_read as global so it is accessible throughout all the file

ft_read :						;non-local label named ft_read, valid in the whole file
mov			rax, 0				;move 0 value in rax, that is the system call number for read
syscall							;call the system call depending on rax value (rsi, rdi and rdx will be set accordingly)
cmp			rax, 0				;compare rax value to 0
jl			.error				;if checked value is strictly bellow, jump to .error label (since error return in read is negative)
ret								;else, return rax value (being the return value of read)
.error :						;local label named .error, valid only in ft_read scope
neg			rax					;get the absolute value of rax since errno can store only positive values and rax value must be negative in error cases
mov			rcx, rax			;move rax value in rcx
push		rcx
call		__errno_location	;call __errno_location function (returns the address of errno variable)
pop			rcx
mov			QWORD [rax], rcx	;move rcx value (absolute value of read return value) to errno (rax is the address of errno, so [rax] is errno itself)
mov			rax, -1				;move -1 value to rax since we want to return the error code of the function
ret								;return rax value
								;see : https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
								;for syscall list.