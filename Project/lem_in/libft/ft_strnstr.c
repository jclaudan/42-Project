/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:50:10 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/20 16:10:06 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && !(ft_strlen(little) > len))
	{
		k = 1;
		while (big[i] == little[j] && k <= len && i < len)
		{
			if (k == len || (k != len && little[j + 1] == '\0'))
				return ((char *)big + (i - j));
			i++;
			j++;
			k++;
		}
		if (k < len)
			i = i - j;
		j = 0;
		i++;
	}
	return (NULL);
}
