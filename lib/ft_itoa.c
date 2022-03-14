/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:18:56 by sshera            #+#    #+#             */
/*   Updated: 2021/10/15 17:19:05 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_number(int n);

char	*ft_itoa(int n)
{
	char	*number;
	int		i;

	i = len_number(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	number = (char *)malloc(sizeof(char) * (i + 1));
	if (number == NULL)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		number[0] = '-';
	}
	number[i--] = '\0';
	while (n / 10 > 0)
	{
		number[i--] = (n % 10) + '0';
		n /= 10;
	}
	number[i] = (n % 10) + '0';
	return (number);
}

int	len_number(int n)
{
	int		i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
