/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:30:12 by jclaudan          #+#    #+#             */
/*   Updated: 2017/01/05 18:31:21 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub_f(char *s, unsigned int start, size_t len)
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
	ft_strdel(&s);
	return (new_string);
}
