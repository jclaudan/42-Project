/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 22:02:22 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/11 22:40:41 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*tp;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(tp = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		tp[i] = f(i, s[i]);
		i++;
	}
	tp[i] = '\0';
	return (tp);
}
