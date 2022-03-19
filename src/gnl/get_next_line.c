/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:32:46 by bcarlee           #+#    #+#             */
/*   Updated: 2022/02/28 15:09:56 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

int	ft_strle(const char *str, char sym)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != sym && str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr_st(const char *str, int sym)
{
	int		i;
	char	*p;

	p = (char *)str;
	i = 0;
	while (p[i] != '\0')
	{
		if (p[i] == (char) sym)
			return (&p[i]);
		i++;
	}
	if (p[i] == (char) sym)
		return (&p[i]);
	return (NULL);
}

int	check_static_var(char *rem, char **line)
{
	char	*p;
	char	*l;

	*line = ft_calloc(1, 1);
	if (!rem)
		return (0);
	if (ft_strchr_st(rem, '\n'))
	{
		l = *line;
		*line = ft_subst(rem, 0, (ft_strle(rem, '\n') + 1), 0);
		free(l);
		p = ft_strchr_st(rem, '\n');
		ft_strlcpy(rem, (p + 1), (ft_strle(p + 1, '\0') + 1));
		return (1);
	}
	else
	{	
		*line = ft_strjoin(*line, rem);
		rem[0] = '\0';
		return (0);
	}
}

void	cut_line(char **line, char *rem, char *buf, int flag)
{
	if ((ft_strchr_st(*line, '\n') && !flag))
	{
		*line = ft_subst(*line, 0, ((ft_strle(*line, '\n') + 1)), 1);
		ft_strlcpy(rem, ((ft_strchr_st(buf, '\n') + 1)), ft_strle(buf, '\0'));
	}
}

char	*get_next_line(int fd)
{
	static char	rem[BUFFER_SIZE + 1];
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			byts;
	int			flag;

	flag = check_static_var(rem, &line);
	byts = 1;
	while (!(ft_strchr_st(line, '\n')) && byts && !flag && byts != -1)
	{
		byts = read(fd, buf, BUFFER_SIZE);
		buf[byts] = '\0';
		if (byts)
			line = ft_strjoin(line, buf);
	}
	if (line[0] == '\0' || byts == -1)
	{
		free(line);
		return (NULL);
	}
	cut_line(&line, rem, buf, flag);
	return (line);
}
