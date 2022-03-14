NAME	=	minishell

SRCS	=	src/main.c\

LIB 	=	./lib/libft.a

HEADER	=	includes/cub3d.h ./lib/libft.h ./mlx/mlx.h

RM		=	rm -f

OBJS	=	$(SRCS:.c=.o)

GCC		= clang

CFLAGS	=	-Wall -Wextra -Werror

FLAG	=	-L mlx -lmlx -framework OpenGL -framework AppKit

$(NAME)	:	$(OBJS) $(HEADER)
			@$(MAKE) -C ./lib
			@$(GCC) $(CFLAGS) $(OBJS) $(LIB) $(FLAG) -o ${NAME}
			@echo "\033[0;32m-----Successful success!-----"

.PHONY	:	all clean fclean re

all		:	$(NAME)

clean	:
			@$(RM) $(OBJS)
			@$(MAKE) clean -C ./lib
			@echo "\033[0;32m-------Clean completed-------"

fclean	:	clean
			@$(RM) $(NAME)
			@echo "\033[0;32m------Fclean completed-------"

re		:	fclean all