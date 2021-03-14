NAME		=	libasm.a

ASM			=	nasm
ASM_FLAGS	=	-f elf64

CC			=	gcc
C_FLAGS		=	-Wall -Wextra -Werror -no-pie

SRCS		=	srcs/ft_strlen.s srcs/ft_strcpy.s srcs/ft_strcmp.s srcs/ft_write.s \
				srcs/ft_read.s srcs/ft_strdup.s
OBJS		=	$(SRCS:%.s=%.o)

SRCS_BONUS	=	srcs/ft_list_push_front_bonus.s	
OBJS_BONUS	=	$(SRCS_BONUS:%.s=%.o)

%.o:				%.s
				$(ASM) $(ASM_FLAGS) $<

all:
				@make $(NAME)

$(NAME):			$(OBJS)
				@ar rc $(NAME) $(OBJS)

bonus:				$(OBJS) $(OBJS_BONUS)
				@ar rc $(NAME) $(OBJS) $(OBJS_BONUS)

exec:				$(NAME)
				@$(CC) $(C_FLAGS) main.c $(NAME) && ./a.out

exec_bonus:			bonus
				@$(CC) $(C_FLAGS) main_bonus.c $(NAME) && ./a.out

clean:
				rm -rf $(OBJS) $(OBJS_BONUS)

fclean:				clean
				rm $(NAME)

re:					fclean all

.PHONY:				all clean fclean re bonus exec exec_bonus