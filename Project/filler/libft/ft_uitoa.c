/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 02:15:53 by jclaudan          #+#    #+#             */
/*   Updated: 2017/02/15 08:45:32 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int nb)
{
	char			*ret;
	int				len;
	unsigned int	nb_tp;

	nb_tp = nb;
	len = 0;
	while (nb_tp >= 10)
	{
		nb_tp /= 10;
		len++;
	}
	ret = ft_strnew(len);
	if (ret)
	{
		ret[len + 1] = '\0';
		while (len >= 0)
		{
			nb_tp = nb % 10;
			ret[len] = '0' + nb_tp;
			nb = nb / 10;
			len--;
		}
	}
	return (ret);
}
