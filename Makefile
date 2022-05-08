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

SRCS_NAME		=	1_main.c			\
					2_run_game.c		\
					3_game_hook.c		\
					4_moving.c			\
					5_1_draw_game.c		\
					5_2_game_math.c		\
					5_3_draw_cfw.c		\
					6_draw_minimap.c	\

MAP_SRCS		=	1_lets_start.c		\
					2_1_init_map.c		\
					2_2_init_map.c		\
					3_1_valid_map.c		\
					3_2_valid_map.c		\
					3_3_valid_map.c		\
					3_4_valid_map.c		\
					4_1_load_img.c		\

UTILS_SRCS		= 	error.c				\
					utils.c				\
					utils2.c			\
					get_next_line.c		\


OBJS_NAME		= $(SRCS_NAME:.c=.o) $(MAP_SRCS:.c=.o) $(UTILS_SRCS:.c=.o)

SRCS			= 	$(addprefix $(SRCS_DIR), $(SRCS_NAME)) \
					$(addprefix $(MAP_DIR), $(MAP_SRCS)) \
					$(addprefix $(UTILS_DIR), $(UTILS_SRCS))

OBJS			= 	$(addprefix $(OBJS_DIR), $(OBJS_NAME))

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror
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

m:					all
					./cub3D map1.cub

.PHONY:				all, clean, fclean, re, create