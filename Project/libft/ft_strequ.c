/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 22:42:58 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/19 07:34:01 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strequ(char const *s1, char const *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return ((int)NULL);
	if (ft_strcmp(s1, s2) == 0)
		return (1);
	else
		return (0);
}
