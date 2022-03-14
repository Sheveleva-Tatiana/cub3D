/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:56:18 by sshera            #+#    #+#             */
/*   Updated: 2021/10/20 11:22:39 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	if (!lst)
		return (0);
	else
	{
		while (lst != NULL)
		{
			counter++;
			lst = lst -> next;
		}
	}
	return (counter);
}
