/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:16:34 by jclaudan          #+#    #+#             */
/*   Updated: 2017/01/16 03:15:54 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dt;
	const char	*sc;
	size_t		sz;
	size_t		len_dst;

	dt = dst;
	sc = src;
	sz = size;
	while (sz-- != 0 && *dt != '\0')
		dt++;
	len_dst = dt - dst;
	sz = size - len_dst;
	if (sz == 0)
		return (len_dst + ft_strlen(sc));
	while (*sc != '\0')
	{
		if (sz != 1)
		{
			*dt++ = *sc;
			sz--;
		}
		sc++;
	}
	*dt = '\0';
	return (len_dst + (sc - src));
}
