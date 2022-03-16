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
    int     count_line;
}           t_map;

typedef struct s_data{
    t_map   *map;
}           t_data;

int ft_check_name(char *name);

void    init_map(char *filename, t_data *data);
void    print_error(int i);
#endif