/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:25:18 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/20 15:44:41 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v'
			|| c == '\r' || c == '\f' || c == '\n')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *nptr)
{
	int		i;
	int		n;
	int		ret;

	i = 0;
	n = 0;
	ret = 0;
	while (is_space(nptr[i]) == 1)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			n = 1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		ret = ret * 10;
		ret = ret + nptr[i] - '0';
		i++;
	}
	if (n == 1)
		return (-ret);
	return (ret);
}
