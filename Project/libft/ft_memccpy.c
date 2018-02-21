/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:00:25 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/11 14:47:40 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*dt;
	const char	*sc;

	dt = dest;
	sc = src;
	while (n-- > 0)
	{
		if ((*dt++ = *sc++) == (char)c)
			return (dt);
	}
	return (NULL);
}
