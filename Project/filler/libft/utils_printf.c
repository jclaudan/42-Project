/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:26:22 by jclaudan          #+#    #+#             */
/*   Updated: 2017/03/13 23:09:24 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*set_char(int c, size_t n)
{
	size_t		i;
	char		*s;

	i = 0;
	if (n <= 0)
	{
		s = ft_strnew(1);
		return (s);
	}
	s = ft_strnew(n);
	while (i < n)
	{
		s[i] = (char)c;
		i++;
	}
	return (s);
}

t_param			*recup_format(const char *format, t_param *p, void *arg)
{
	p->arg = arg;
	p->form = ft_strdup(format);
	p->str_p = stock_param(p->form + 1);
	p = set_flags(p);
	p = init_t_param(p);
	p = set_modif(p);
	if (p->wildcard_f == 1)
	{
		if (p->wildchamp < 0)
		{
			p->less = 1;
			p->wildchamp = p->wildchamp * (-1);
		}
		p->champ = p->wildchamp;
	}
	if (p->wildcard_p == 1)
	{
		p->precis = p->wildprecis;
	}
	return (p);
}

void			init_a_null_kit(t_param *p)
{
	p->str1 = NULL;
	p->count_prct = 0;
	p->wildcard_p = 0;
	p->len_wild = 0;
	p->wildcard_f = 0;
	p->wildchamp = 0;
	p->wildprecis = 0;
	p->big_s = 0;
	p->flag = 0;
	p->size = 0;
	p->frm = NULL;
}

t_param			*init_a_null(t_param *p, const char *format)
{
	init_a_null_kit(p);
	p->frm = ft_strdup(format);
	p->i = 0;
	p->arg = NULL;
	p->str_p = NULL;
	p->conv = '\0';
	p->champ = 0;
	p->precis = 0;
	p->hasht = 0;
	p->zero = 0;
	p->less = 0;
	p->plus = 0;
	p->space = 0;
	p->j = 0;
	p->z = 0;
	p->hh = 0;
	p->ll = 0;
	p->h = 0;
	p->l = 0;
	return (p);
}

t_param			*set_flags(t_param *p)
{
	if (ft_strchr(p->str_p, '#'))
		p->hasht = 1;
	else
		p->hasht = 0;
	if (is_zero(p->str_p, '0') == 1)
		p->zero = 1;
	else
		p->zero = 0;
	if (ft_strchr(p->str_p, '+'))
		p->plus = 1;
	else
		p->plus = 0;
	if (ft_strchr(p->str_p, '-'))
		p->less = 1;
	else
		p->less = 0;
	if (ft_strchr(p->str_p, ' '))
		p->space = 1;
	else
		p->space = 0;
	return (p);
}
