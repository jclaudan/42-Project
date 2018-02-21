/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_is_wildcard.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 23:16:06 by jclaudan          #+#    #+#             */
/*   Updated: 2017/03/13 23:43:59 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_wildcard(char c)
{
	if (ft_strchr("*", c))
		return (1);
	return (0);
}

int		if_wildcard_kit(const char *form, t_param *p, void *arg)
{
	size_t	i;

	i = 0;
	while (form[i] && form[i] != '.')
	{
		if (is_wildcard(form[i]) == 1)
		{
			p->wildcard_f = 1;
			p->wildchamp = (int)arg;
			p->len_wild += (i + 1);
		}
		++i;
	}
	if (form[i] == '.')
		while (form[i] && is_conv(form[i]) != 1)
		{
			if (is_wildcard(form[i]) == 1)
			{
				if (p->wildcard_f == 0)
					p->wildprecis = (int)arg;
				p->wildcard_p = 1;
			}
			++i;
		}
	return (1);
}

int		if_wildcard(const char *form, t_param *p, void *arg)
{
	if_wildcard_kit(form, p, arg);
	if (p->wildcard_f == 0 && p->wildcard_p == 0)
	{
		p->arg = arg;
		return (0);
	}
	return (1);
}

int		if_wildcard_p(t_param *p, void *arg)
{
	p->wildprecis = (int)arg;
	return (0);
}
