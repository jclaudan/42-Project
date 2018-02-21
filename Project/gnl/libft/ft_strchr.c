/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:15:37 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/10 12:12:08 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchr(const char *s, int c)
{
	size_t		i;
	const char	*sc;

	i = 0;
	sc = s;
	while (i <= ft_strlen(s) && s)
	{
		if (*sc == (char)c)
			return ((char *)sc);
		sc++;
		i++;
	}
	return (NULL);
}
