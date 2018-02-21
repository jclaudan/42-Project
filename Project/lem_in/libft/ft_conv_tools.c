/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:20:48 by jclaudan          #+#    #+#             */
/*   Updated: 2017/03/13 21:29:09 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*stock_param(char *s)
{
	int	i;

	i = 0;
	while (is_conv(s[i]) == 0 && s[i])
	{
		i++;
	}
	return (ft_strsub(s, 0, i + 1));
}

t_param		*set_modif(t_param *p)
{
	if (ft_strchr(p->str_p, 'j'))
		p->j = 1;
	else
		p->j = 0;
	if (ft_strchr(p->str_p, 'z'))
		p->z = 1;
	else
		p->z = 0;
	if (ft_strstr(p->str_p, "hh"))
		p->hh = 1;
	else
		p->hh = 0;
	if (ft_strchr(p->str_p, 'h') && p->hh == 0)
		p->h = 1;
	else
		p->h = 0;
	if (ft_strstr(p->str_p, "ll"))
		p->ll = 1;
	else
		p->ll = 0;
	if (ft_strchr(p->str_p, 'l') && p->ll == 0)
		p->l = 1;
	else
		p->l = 0;
	return (p);
}

t_param		*set_champ(t_param *p)
{
	int		i;
	int		j;
	char	*tp;

	tp = ft_strnew(ft_strlen_p(p->str_p));
	i = 0;
	j = 0;
	while (p->str_p[i] && p->str_p[i] != '.')
	{
		if (ft_isdigit(p->str_p[i]))
		{
			tp[j] = p->str_p[i];
			j++;
		}
		i++;
	}
	tp[j] = '\0';
	p->champ = ft_atoi(tp);
	ft_memdel((void *)&tp);
	return (p);
}

t_param		*set_precis(t_param *p)
{
	int		i;
	char	*tp;

	i = 1;
	if ((tp = ft_strchr(p->str_p, '.')))
	{
		while (ft_isdigit(tp[i]) && tp[i])
		{
			i++;
		}
		tp = ft_strsub(tp, 1, i);
		p->precis = ft_atoi(tp);
		ft_memdel((void *)&tp);
		return (p);
	}
	else
	{
		p->precis = 0;
		return (p);
	}
}

t_param		*set_conv(t_param *p)
{
	int		i;

	i = 0;
	while (p->str_p[i])
	{
		if (not_in_list(p->str_p[i]) == 1)
		{
			p->conv = p->str_p[i];
			return (p);
		}
		if (is_conv(p->str_p[i]))
		{
			p->conv = p->str_p[i];
			return (p);
		}
		i++;
	}
	p->conv = '\0';
	return (p);
}
