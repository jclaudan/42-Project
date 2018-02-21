/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:00:57 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/11 19:33:53 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*tp1;
	const unsigned char	*tp2;

	tp1 = (const unsigned char *)s1;
	tp2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*tp1 != *tp2)
			return ((*tp1 - *tp2));
		else
		{
			tp1++;
			tp2++;
		}
	}
	return (0);
}
