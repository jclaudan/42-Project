/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 02:28:27 by jclaudan          #+#    #+#             */
/*   Updated: 2017/02/15 03:47:29 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_oitoa(unsigned int nb)
{
	char			*ret;
	int				len;
	unsigned int	nb_tp;

	nb_tp = nb;
	len = 0;
	while (nb_tp > 7)
	{
		nb_tp = nb_tp / 8;
		len++;
	}
	ret = ft_strnew(len);
	if (ret)
	{
		ret[len + 1] = '\0';
		while (len >= 0)
		{
			nb_tp = nb % 8;
			ret[len] = '0' + nb_tp;
			nb = nb / 8;
			len--;
		}
	}
	return (ret);
}
