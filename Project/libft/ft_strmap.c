/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:06:31 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/11 21:49:09 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*tp;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(tp = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		tp[i] = f(s[i]);
		i++;
	}
	tp[i] = '\0';
	return (tp);
}
