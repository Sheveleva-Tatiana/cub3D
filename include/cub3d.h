/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:32:25 by bcarlee           #+#    #+#             */
/*   Updated: 2022/05/08 15:24:49 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define N 1
# define S 2
# define W 3
# define E 4
# define PI 3.14159265
# define WIN_WIDTH 1200
# define WIN_HEIGHT 500

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include <fcntl.h>
# include "../lib/libft.h"
# include "../mlx/mlx.h"

typedef struct s_draw{
	int		x;
	int		y;
	double	angle;
	double	angle_start;
	double	angle_end;
	double	angle_step;
	double	cos;
	double	sin;
	double	deltadistx;
	double	deltadisty;
	double	sidedistx;
	double	sidedisty;
	int		stepx;
	int		stepy;
	int		mapx;
	int		mapy;
	int		hit;
	int		side;
	double	perpwalldist;
	int		lineheight;
	double	wallx;
	int		drawstart;
	int		drawend;
	int		texx;
	double	step;
	double	texpos;
	int		texy;
	int		tn;
}			t_draw;

typedef struct s_tex
{
	char	*path;
	void	*ptr;
	int		*data;
	int		width;
	int		height;
	int		bpp;
	int		size;
	int		endian;
}			t_tex;

typedef struct s_img {
	void	*img;
	void	*img2;
	int		*data;
	int		bpp;
	int		ll;
	int		e;
}			t_img;

typedef struct s_ply{
	double	x;
	double	y;
	double	angle;
	double	move_k;
	double	rotate_k;
	double	fov;
}			t_ply;

typedef struct s_map{
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
	int		c_color;
	int		f_color;
	t_tex	*tex;
	int		count_line;
}			t_map;

typedef struct s_data{
	int		err;
	void	*mlx;
	void	*win;
	char	active_key[250];
	t_map	*map;
	t_img	*img;
	t_ply	*ply;
}			t_data;

void	lets_start(char *filename, t_data *data, int count, int start);
//2_init_map.c
void	check_texture(t_data *data);
int		get_count_line(char *file, int *count);
void	copy_map(char *file, int start, t_data *data, int end);
void	trim_space(t_data *data);
int		proverka(char *str, t_data *data);
void	get_data(char *line, t_data *data, int flag);
//valid.map
void	check_count_line(int count, t_data *data);
void	valid_map(t_data *data);
void	put_player(int i, int j, t_data *data);
void	check_close_wall(t_data *data);
void	check_close_wall_inside(t_data *data);
void	check_sym(t_data *data, int i, int j);
void	check_next_sym(t_data *data, int i, int j);
void	rgb_to_hex(t_data *d);
//load_image
void	load_image(t_data *data);
//utils
char	*get_next_line(int fd);
void	print_error(int i);
void	print_error_and_exit(t_data *data, char *str);
char	*ft_subst(char *str, int s, int l, int flag);
void	clear_arr(char **arr);
int		ft_isdigit_char(char *str);
void	clear_and_exit(t_data *data);
void	free_all(t_data *data);
int		size_arr(char **arr);
int		ft_strle(const char *str, char sym);
//game
void	run_game(t_data *data);
void	game_hook(t_data *data);
//moving
void	moving(t_data *data);
//draw_game
void	draw_game(t_data *data);
void	init_texture(t_tex *tex, t_data *data);
//game_math
void	draw_step_side(t_data *data, t_draw *draw);
void	hit_wall(t_data *cub, t_map *map, t_draw *draw, t_ply *player);
void	height_wall(t_data *cub, t_draw *draw);
void	draw_minimap(t_data *data);
//cfw
void	walls(t_data *cub, t_map *map, t_draw *draw);
void	ceiling(t_data *cub, t_draw *draw);
void	flour(t_data *cub, t_draw *draw);

#endif