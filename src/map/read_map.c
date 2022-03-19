#include "../../include/cub3d.h"

void	get_data(char *line, t_data *data, int flag)
{
	char	**arr;
	char	*l;
	int		i;

	i = 0;
	l = ft_substr(line, 1, ft_strlen(line));
	free(line);
	line = ft_strtrim(l, " ");
	free(l);
	arr = ft_split(line, ',');
	while (arr[i])
	{
		if (!(ft_isdigit_char(arr[i])))
		{
			printf("Incorrect data");
			exit (1);
		}
		if (flag == 0)
			data->map->f[i] = ft_atoi(arr[i]);
		else
			data->map->c[i] = ft_atoi(arr[i]);
		i++;
	}
}

void	copy_map(char *file, int start, t_data *data, int end)
{
	int		fd;
	char	*line;
	int 	i;
	int		k;

	fd = open(file, O_RDONLY);
	i = 0;
	k = 0;
	line = get_next_line(fd);
	data->map->map = malloc(sizeof(char *) * ((end - start) + 1) + 1);
	while(line)
	{
		if (i >= start)
		{
			data->map->map[k] = line;
			k++;
		}
		line = get_next_line(fd);
		i++;
	}
	data->map->map[k] = NULL;
	close(fd);
}