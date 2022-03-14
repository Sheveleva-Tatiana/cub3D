/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:01:39 by sshera            #+#    #+#             */
/*   Updated: 2021/10/19 21:23:02 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		i;
	int		j;
	int		c;

	i = 0;
	c = 0;
	if (!s1)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen((char *)s1) - 1;
	while (s1[j] && ft_strchr(set, s1[j]) && j > i)
		j--;
	p = (char *)malloc(sizeof(char) * (j - i + 2));
	if (!p)
		return (NULL);
	while (i < j + 1)
	{
		p[c] = s1[i];
		i++;
		c++;
	}
	p[c] = '\0';
	return (p);
}
