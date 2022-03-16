NAME	=	cub3d

SRCS	=	src/main.c				src/map/init_map.c				src/utils/error.c\

LIB 	=	./lib/libft.a

HEADER	=	includes/cub3d.h ./lib/libft.h ./minilibx_opengl_20191021/mlx.h

RM		=	rm -f

OBJS	=	$(SRCS:.c=.o)

GCC		= clang

CFLAGS	=	-Wall -Wextra -Werror

FLAG	=	-L minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

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