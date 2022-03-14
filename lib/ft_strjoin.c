/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlee <bcarlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:19:56 by sshera            #+#    #+#             */
/*   Updated: 2022/02/28 15:48:50 by bcarlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*newstr;
	size_t	lens1;
	size_t	lens2;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen((char *)s1);
	lens2 = ft_strlen((char *)s2);
	newstr = (char *)malloc(sizeof(char) * (lens1 + lens2) + 1);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (lens1-- > 0)
		newstr[i++] = s1[j++];
	j = 0;
	while (lens2-- > 0)
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	free(s1);
	return (newstr);
}
