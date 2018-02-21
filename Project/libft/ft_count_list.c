/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 22:51:27 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/21 01:00:14 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count_list(t_list *lst)
{
	size_t	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
