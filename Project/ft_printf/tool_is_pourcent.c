/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_is_pourcent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 23:13:25 by jclaudan          #+#    #+#             */
/*   Updated: 2017/03/13 23:41:10 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				if_pourcent(char *format)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			return (i);
		}
		++i;
	}
	return (0);
}

t_param			*if_pourcent_champ(t_param *p)
{
	int	i;

	i = 0;
	while (p->str_p[i])
	{
		if (p->str_p[i] == '-')
			p->less = 1;
		if (p->str_p[i] == '0' && p->str_p[i + 1] != '0')
			p->zero = 1;
		i++;
	}
	if (p->champ <= 0)
		p->str = set_char('%', 1);
	else if (p->zero == 0 && p->less == 1)
		p->str = ft_strjoin_f("%", set_char(' ', p->champ - 1), 2);
	else if (p->zero == 1 && p->less == 1)
		p->str = ft_strjoin_f("%", set_char(' ', p->champ - 1), 2);
	else if (p->zero == 1 && p->less == 0)
		p->str = ft_strjoin_f(set_char('0', p->champ - 1), "%", 1);
	else
		p->str = ft_strjoin_f(set_char(' ', p->champ - 1), "%", 1);
	p->size += ft_strlen_p(p->str);
	ft_putstr(p->str);
	return (p);
}

t_param			*add_pourcent(t_param *p, char *form, int len)
{
	if (p->conv == '%')
	{
		p->str_p = ft_strsub(form + len + 1, 0, if_pourcent(form + len + 1));
		p = set_champ(p);
		p = if_pourcent_champ(p);
		p->i += if_pourcent(form + p->i) + 1;
	}
	return (p);
}

void			print_one_char(t_param *p, char frm_char, int opt)
{
	if (opt == 1)
		p->size += 0;
	if (opt == 2 && p->flag != 1)
	{
		if (frm_char == '%')
			p->size += 0;
		else
		{
			p->size += 1;
			ft_putchar(frm_char);
		}
	}
}
