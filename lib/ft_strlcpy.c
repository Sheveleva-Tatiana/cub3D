/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:31:58 by sshera            #+#    #+#             */
/*   Updated: 2021/10/14 11:26:40 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size_src;

	i = 0;
	while (src[i])
		i++;
	size_src = i;
	if (dst == NULL)
		return (0);
	i = 0;
	if (dstsize < 1)
		return (size_src);
	while (i < (dstsize - 1) && size_src > i)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (size_src);
}
