/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:00:10 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/20 19:59:20 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new_string;

	i = 0;
	if (!(new_string = (char *)malloc(sizeof(char) * (len + 1))) || !s)
		return (NULL);
	while (s[i] && i < len)
	{
		new_string[i] = s[i + start];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
