NAME			=	cub3D

INCLUDES		=	-I ./include/ -I ./mlx/

SRCS_DIR		=	./srcs/
MAP_DIR			=	./srcs/map/
UTILS_DIR		=	./srcs/utils/
OBJS_DIR		=	./objs/
LIBFT_DIR		=	./lib/
LIBRARY			=	./lib/libft.a
MLX_DIR			=	./mlx/
MLX_LIB			=	./mlx/libmlx.a

SRCS_NAME		=	main.c					\
					run_game.c

MAP_SRCS		=	get_next_line.c			\
					init_map.c				\
					read_map.c				\
					valid_map.c				\
					valid_map2.c			\
					valid_map_utils.c		\

UTILS_SRCS		= 	error.c					\
					utils.c					\
					utils2.c				\


OBJS_NAME		= $(SRCS_NAME:.c=.o) $(MAP_SRCS:.c=.o) $(UTILS_SRCS:.c=.o)

SRCS			= 	$(addprefix $(SRCS_DIR), $(SRCS_NAME)) \
					$(addprefix $(MAP_DIR), $(MAP_SRCS)) \
					$(addprefix $(UTILS_DIR), $(UTILS_SRCS))

OBJS			= 	$(addprefix $(OBJS_DIR), $(OBJS_NAME))

CC				= gcc

#CFLAGS			= -Wall -Wextra -Werror
MLX_FLAGS		= -Lmlx -lmlx -framework OpenGL -framework AppKit

all:				$(NAME)

$(NAME):			$(OBJS)
					@($(MAKE)	-C		$(MLX_DIR))
					@($(MAKE)	-C		$(LIBFT_DIR))
					@($(CC)	$(LIBRARY)	$(MLX_LIB)	-o	$(NAME)	$(OBJS)	$(MLX_FLAGS))

$(OBJS):			$(SRCS)
					@(mkdir -p $(OBJS_DIR))
					@($(CC)	$(INCLUDES)	-c	$(SRCS))
					@(mv	$(OBJS_NAME)	$(OBJS_DIR))
clean:
					@(make	clean -C	$(LIBFT_DIR))
					@(make	clean -C	$(MLX_DIR))
					@(rm 	-rf			$(OBJS))

fclean:				clean
					@(rm	-rf	$(NAME))
					@(rm    -rf $(LIBRARY))
					@(rm	-rf	objs)
					@(rm	-f $(SCREEN))

re:					fclean all

.PHONY:				all, clean, fclean, re, create