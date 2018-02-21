/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_is_this.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:25:54 by jclaudan          #+#    #+#             */
/*   Updated: 2017/03/13 16:31:04 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	if_is_c_kit_1(t_param *p, wchar_t c)
{
	p = conv_to_unicode(c, p);
	ft_putstr(p->str);
	p->size += ft_strlen_p(p->str);
	if ((char)p->arg == 0 && p->plus != 1)
		p->size += 1;
	if (p->plus == 1)
		p->size += 1;
}

char	*if_is_c_kit_2(t_param *p, char *s, int flag)
{
	if (p->champ != 0 && p->precis == 0)
	{
		if (p->zero == 1)
			s = set_char('0', p->champ - 1);
		else
			s = set_char(' ', p->champ - 1);
		p->size += 1;
	}
	else
	{
		if (flag == 1)
			p->size += 1;
		if (flag == 2)
			p->size += 0;
	}
	return (s);
}

void	if_is_c_kit_3(t_param *p, char c, char *s)
{
	c = (unsigned char)c;
	*s = c;
	s = add_flags(p, s);
	if ((char)p->arg == 0)
	{
		s[0] = '\0';
		s[1] = '\0';
		s = if_is_c_kit_2(p, s, 1);
	}
	else if ((char)p->arg == '0')
	{
		s[0] = '0';
		s[1] = '\0';
		s = if_is_c_kit_2(p, s, 2);
	}
	ft_putstr(s);
	p->size += ft_strlen_p(s);
}

int		if_is_c(t_param *p)
{
	char	c;
	char	*s;

	s = ft_strnew(1);
	c = (long long int)p->arg;
	if (p->conv == 'C' || (p->conv == 'c' && p->l == 1))
		if_is_c_kit_1(p, (wchar_t)p->arg);
	if (p->conv == 'C' && p->hh == 1)
		return (1);
	if (p->conv == 'c' && p->l == 0)
	{
		if_is_c_kit_3(p, c, s);
		return (1);
	}
	ft_memdel((void*)&s);
	return (0);
}

int		if_is_other(t_param *p)
{
	char	*s;

	s = ft_strnew(1);
	if (not_in_list(p->conv) == 1)
	{
		s[0] = p->conv;
		s[1] = '\0';
		s = add_flags(p, s);
		p->size += ft_strlen_p(s);
		if (p->str_p[p->i + 2])
			p->i += -1;
		ft_putstr(s);
		return (1);
	}
	ft_memdel((void*)&s);
	return (0);
}
