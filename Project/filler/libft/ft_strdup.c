/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:16:28 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/11 14:49:22 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*tp;

	i = 0;
	if (!(tp = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		tp[i] = s1[i];
		i++;
	}
	tp[i] = '\0';
	return (tp);
}
