/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:00:34 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/18 02:23:34 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dt;
	char	*sc;
	int		i;
	size_t	j;

	i = 0;
	j = n;
	dt = (char *)dest;
	sc = (char *)src;
	if (j == 0 || dest == src)
		return (dest);
	while (--j)
	{
		dt[i] = sc[i];
		i++;
	}
	dt[i] = sc[i];
	return (dest);
}
