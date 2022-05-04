/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:32:25 by bcarlee           #+#    #+#             */
/*   Updated: 2022/02/28 16:02:46 by sshera           ###   ########.fr       */
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
# define WALL_NORTH 0
# define WALL_SOUTH 1
# define WALL_WEST 2
# define WALL_EAST 3

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
	int		door;
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
	int 	*data;
	int		width;
	int		height;
	int		bpp;
	int		size;
	int		endian;
	int		count_width;
}			t_tex;


typedef struct s_img {
	void	*img;
	int	*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_ply{
	double	x;
	double 	y;
	int 	pos;
	double 	angle;
	double 	*buffer;
	double  move_k;
	double 	rotate_k;
	double 	fov;
}			t_ply;

typedef struct s_map{
    char    **map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int 	f[3];
	int 	c[3];
	int 	c_color;
	int		f_color;
	t_tex	*tex;
    int     count_line;
}           t_map;

typedef struct s_data{
    t_map   *map;
    void 	*mlx;
	t_img 	*img;
    void 	*win;
	char 	*active_key;
	t_ply	*ply;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	int		tex_w;
	int		tex_h;
	int		wall_side;
	double	dir_y;
	double	dir_x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	plane_x;
	double	plane_y;
	int 	map_x;
	int		map_y;
	int 	delta_dist_x;
	int 	delta_dist_y;
	int		step_x;
	double 	side_dist_x;
	int		step_y;
	double 	side_dist_y;
	double	perp_wall_dist;
	double	dist;
	int		draw_start;
	int		draw_end;

}           t_data;

void	game_hook(t_data *data);
void	moving(t_data *data);

void	init_camera_plane(t_data *data);

void	init_direction(int y, int x, t_data *o);

void		draw(t_data *data);
void	ft_pixel_put(int y, int x, t_data *data, unsigned int color);


int 	ft_check_name(char *name);
void	run_game(t_data *data);

int		ft_strle(const char *str, char sym);

void    lets_start(char *filename, t_data *data);
void    print_error(int i);
char	*ft_subst(char *str, int s, int l, int flag);
char	*get_next_line(int fd);
void	get_data(char *line, t_data *data, int flag);
void	clear_arr(char **arr);
int		ft_isdigit_char(char *str);
void	copy_map(char *file, int start, t_data *data, int end);
void	trim_space(t_data *data);
void	init_struct_map(t_data *data);
void	clear_and_exit(t_data *data);
void	valid_map(t_data *data);
int 	size_arr(char **arr);
void	check_close_wall_inside(t_data *data);
void	check_sym(t_data *data, int i, int j, int *err);
void	check_next_sym(t_data *data, int i, int j, int *err);
void	load_image(t_data *data);
void	print_error_and_exit(t_data *data, char *str);
#endif