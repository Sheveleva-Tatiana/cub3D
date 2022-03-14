/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:22:19 by sshera            #+#    #+#             */
/*   Updated: 2021/10/13 09:02:54 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	size_t	i;

	i = 0;
	arr = malloc(count * size);
	if (arr == NULL)
		return (NULL);
	while (i < count * size)
	{
		*((unsigned char *)arr + i) = 0;
		i++;
	}
	return (arr);
}
