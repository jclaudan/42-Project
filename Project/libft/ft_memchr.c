/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:00:27 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/09 21:57:04 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*tp;

	tp = (const unsigned char *)s;
	while (n-- > 0)
	{
		if (*tp++ == (unsigned char)c)
			return ((void *)tp - 1);
	}
	return (NULL);
}
