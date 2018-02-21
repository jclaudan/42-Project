/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:08:48 by jclaudan          #+#    #+#             */
/*   Updated: 2017/03/13 23:07:33 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_conv(char c)
{
	if (ft_strchr("sSpdDioOuUxXcC%", c))
		return (1);
	return (0);
}

int		is_conv_in(char *form, t_param *p)
{
	size_t	i;

	i = 0;
	while (form[i] && is_conv(form[i]) == 0)
	{
		if (not_in_list(form[i]) == 1)
		{
			p->conv = form[i];
			return (1);
		}
		++i;
	}
	p->conv = form[i];
	if (i == ft_strlen_p(form))
		return (0);
	else
		return (1);
}

int		is_flags(char c)
{
	if (ft_strchr("#0-+ ", c))
		return (1);
	return (0);
}

int		is_modif(char c)
{
	if (ft_strchr("hljz", c))
		return (1);
	else
		return (0);
}

int		is_zero(char *s, char c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == c && !(s[i - 1] >= '1' && s[i - 1] <= '9'))
			return (1);
	}
	return (0);
}
