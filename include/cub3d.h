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

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include "../lib/libft.h"
# include "../minilibx_opengl_20191021/mlx.h"

typedef struct s_map{
    char    **map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int 	f[3];
	int 	c[3];
    int     count_line;
}           t_map;

typedef struct s_data{
    t_map   *map;
}           t_data;

int ft_check_name(char *name);

void    init_map(char *filename, t_data *data);
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
#endif