#include "../includes/cub3d.h"

int ft_check_name(char *name)
{
    if (ft_strlen(name) > 4)
    {
        if (ft_strnstr(&argv[len - 4], ".cub", 4))
            return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2 && ft_check_name(av[1]))
        init_map(av[1]);
    else
        write(2, "Error : Invalid arguments\n", 26);
    return (0);
}