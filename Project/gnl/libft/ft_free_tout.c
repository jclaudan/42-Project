/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 04:22:13 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/22 23:36:29 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_tout(void **afree)
{
	size_t	i;

	i = 0;
	if (!afree)
		return ;
	while (afree[i])
	{
		free(afree[i]);
		i++;
	}
	free(afree);
	return ;
}