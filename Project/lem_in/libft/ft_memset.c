/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:15:07 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/11 14:48:17 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sc;

	sc = s;
	i = 0;
	if (n == 0)
		return (s);
	while (i < n)
	{
		sc[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
