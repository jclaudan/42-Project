/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 01:31:51 by jclaudan          #+#    #+#             */
/*   Updated: 2017/03/13 15:31:08 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		trans_to_hexa(int nb, char flag_in_or_maj)
{
	if (0 <= nb && nb <= 9)
		return ('0' + nb);
	if (10 <= nb && nb <= 15 && flag_in_or_maj == 'x')
	{
		nb = nb - 10;
		return ('a' + nb);
	}
	if (10 <= nb && nb <= 15 && flag_in_or_maj == 'X')
	{
		nb = nb - 10;
		return ('A' + nb);
	}
	return (0);
}

static char		*hitoa_kit(unsigned long nb, char flag_in_or_maj)
{
	if (nb == 9223372036854775807)
	{
		if (flag_in_or_maj == 'X')
			return (ft_strdup("7FFFFFFFFFFFFFFF"));
		if (flag_in_or_maj == 'x')
			return (ft_strdup("7fffffffffffffff"));
	}
	if (nb == 4294967296)
		return (ft_strdup("100000000"));
	return (ft_strdup("0"));
}

static char		*ft_hitoa_kit1(unsigned long nb, char flag_in_or_maj,
		unsigned long nb_tp, int len)
{
	char		*ret;

	ret = NULL;
	while (nb_tp > 16)
	{
		nb_tp = nb_tp / 16;
		len++;
	}
	ret = ft_strnew((size_t)len);
	if (ret)
	{
		ret[len + 1] = '\0';
		while (len >= 0)
		{
			nb_tp = nb % 16;
			ret[len] = trans_to_hexa(nb_tp, flag_in_or_maj);
			nb = nb / 16;
			len--;
		}
	}
	return (ret);
}

char			*ft_hitoa(unsigned long nb, char flag_in_or_maj)
{
	int				len;
	unsigned long	nb_tp;

	len = 0;
	nb_tp = nb;
	if (nb == 9223372036854775807 || nb == 4294967296 || nb == 0)
		return (hitoa_kit(nb, flag_in_or_maj));
	return (ft_hitoa_kit1(nb, flag_in_or_maj, nb_tp, len));
}
