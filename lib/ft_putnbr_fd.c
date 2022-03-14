/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:13:10 by sshera            #+#    #+#             */
/*   Updated: 2021/10/20 12:23:32 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_razryad(int n)
{
	int	raz;

	raz = 0;
	while (n > 9)
	{
		n = n / 10;
		raz++;
	}
	return (raz);
}

int	ft_square(int razryad)
{
	int	result;

	result = 1;
	while (razryad != 0)
	{
		result = result * 10;
		razryad--;
	}
	return (result);
}

void	ft_putnbr_fd(int nb, int fd)
{
	int	razryad;
	int	temp;

	if (nb == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	razryad = ft_razryad(nb);
	while (razryad >= 0)
	{
		temp = nb / ft_square(razryad);
		ft_putchar_fd('0' + temp, fd);
		nb = nb % ft_square(razryad);
		razryad--;
	}
}
