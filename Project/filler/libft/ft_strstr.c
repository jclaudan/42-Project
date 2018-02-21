/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:31:16 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/09 21:34:52 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		if (big[i] == little[j])
		{
			while (big[i] == little[j] && little[j] != '\0')
			{
				i++;
				j++;
			}
			if (little[j] == '\0')
				return ((char *)big + (i - j));
			else
				i = i - j;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
