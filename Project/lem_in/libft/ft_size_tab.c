/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:25:52 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/11 14:47:10 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_size_tab(char **tab)
{
	size_t	i;

	i = 0;
	if (tab)
		while (tab[i])
			i++;
	return (i);
}
