/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:34:32 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/19 08:16:28 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_separator(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*new_string;
	size_t	end;
	size_t	start;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	while (is_separator(s[start]) == 1)
	{
		start++;
	}
	while (is_separator(s[end - 1]) == 1)
	{
		end--;
	}
	if (end < start)
		end = start;
	new_string = ft_strnew(end - start);
	if (!new_string)
		return (NULL);
	return (ft_strncpy(new_string, s + start, end - start));
}
