/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 03:08:19 by jclaudan          #+#    #+#             */
/*   Updated: 2017/03/13 15:32:20 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*trans_char(long long int div, long long int n,
		long long int i, int neg)
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

static char			*litoa_kit(long long int n)
{
	if (n == 9223372036854775807)
		return (ft_strdup("9223372036854775807"));
	if (n == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	return (ft_strdup("0"));
}

char				*ft_litoa(long long int n)
{
	int						neg;
	long long int			div;
	unsigned long long int	i;
	unsigned long long int	nn;

	i = 1;
	neg = 0;
	div = 1;
	if (n == 9223372036854775807 || n == -9223372036854775807 - 1 || n == 0)
		return (litoa_kit(n));
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
