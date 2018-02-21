/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:29:34 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/20 16:16:29 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*memoire;

	if (!(memoire = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(memoire, size);
	return (memoire);
}
