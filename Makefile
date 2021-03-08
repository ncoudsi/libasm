NAME		=	libasm.a

ASM			=	nasm
ASM_FLAGS	=	-f elf64

CC			=	gcc
C_FLAGS		=	-Wall -Wextra -Werror

SRCS		=	srcs/ft_strlen.s srcs/ft_strcpy.s srcs/ft_strcmp.s srcs/ft_write.s
OBJS		=	$(SRCS:%.s=%.o)

%.o:				%.s
				$(ASM) $(ASM_FLAGS) $<

all:
				@make $(NAME)

$(NAME):			$(OBJS)
				@ar rc $(NAME) $(OBJS)

exec:				$(NAME)
				$(CC) $(C_FLAGS) main.c $(NAME) && ./a.out

clean:
				rm -rf $(OBJS)

fclean:				clean
				rm $(NAME)

re:					fclean all

.PHONY:				all clean fclean re