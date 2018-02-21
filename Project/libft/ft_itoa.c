/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:27:25 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/19 08:00:38 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*trans_char(int div, unsigned int n, int i, int neg)
{
	char			*nb;

	if (!(nb = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	if (neg == 1)
	{
		nb[i] = '-';
		i++;
	}
	while (div > 0)
	{
		nb[i] = (n / div) % 10 + '0';
		div = div / 10;
		i++;
	}
	nb[i] = '\0';
	return (nb);
}

char				*ft_itoa(int n)
{
	int				neg;
	int				div;
	int				i;
	unsigned int	nn;

	i = 1;
	neg = 0;
	div = 1;
	if (n < 0)
	{
		neg = 1;
		nn = n * -1;
		i++;
	}
	else
		nn = n;
	while ((nn / div) >= 10)
	{
		div = div * 10;
		i++;
	}
	return (trans_char(div, nn, i, neg));
}
