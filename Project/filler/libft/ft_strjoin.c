/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:27:31 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/19 07:42:22 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	l_s1;
	size_t	l_s2;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	l_s1 = ft_strlen((char *)s1);
	l_s2 = ft_strlen((char *)s2);
	if (!(new_string = (char *)malloc(sizeof(char) * (l_s1 + l_s2 + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		new_string[i] = (char)s1[i];
		i++;
	}
	j = -1;
	while (s2[++j] != '\0')
		new_string[i + j] = s2[j];
	new_string[i + j] = '\0';
	return (new_string);
}
