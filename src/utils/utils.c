
#include "../../includes/cub3d.h"

int ft_check_name(char *name)
{
	if (ft_strlen(name) > 4)
		if (ft_strnstr(&name[ft_strlen(name) - 4], ".cub", 4))
			return (1);
	return (0);
}
