/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_is_x_or_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:30:46 by jclaudan          #+#    #+#             */
/*   Updated: 2017/03/13 23:03:10 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*tool_if_is_x(t_param *p, char *s)
{
	if (p->conv == 'x')
		s = ft_strjoin_f("0x", s, 2);
	if (p->conv == 'X')
		s = ft_strjoin_f("0X", s, 2);
	return (s);
}

void		tool_if_is_x2(t_param *p, char *s, long long int un_int, int flag)
{
	if (flag == 1)
	{
		ft_putstr(s);
		p->size += ft_strlen_p(s);
		ft_memdel((void*)&s);
	}
	else if (flag == 2)
	{
		if (p->two_z == 1 && un_int == 0)
			p->size += -1;
		if (un_int == 0 && p->two_z != 1)
		{
			p->size += -1;
			p->two_z = 1;
		}
		ft_putstr(s);
		p->size += ft_strlen_p(s) + 1;
		ft_memdel((void*)&s);
		return ;
	}
	return ;
}

int			if_is_x(t_param *p)
{
	char			*s;
	long long int	un_int;

	un_int = (long long int)p->arg;
	if (p->conv == 'x' || p->conv == 'X')
	{
		if (p->ll == 1 || p->l == 1 || p->j == 1 || p->z == 1)
			s = ft_hitoa((long long int)un_int, p->conv);
		else if (p->h == 1)
			s = ft_hitoa((unsigned short int)un_int, p->conv);
		else if (p->hh == 1)
			s = ft_hitoa((unsigned char)un_int, p->conv);
		else
			s = ft_hitoa((unsigned int)un_int, p->conv);
		s = add_flags(p, s);
		if (p->hasht == 1 && p->less == 1)
			s = tool_if_is_x(p, s);
		if (!(un_int == 0 && p->precis == 0 && ft_strchr(p->str_p, '.')))
			tool_if_is_x2(p, s, un_int, 1);
		else
			tool_if_is_x2(p, s, un_int, 2);
		return (1);
	}
	return (0);
}

t_param		*tool_if_is_u(t_param *p, char *s)
{
	p->size += ft_strlen_p(s);
	ft_putstr(s);
	ft_memdel((void*)&s);
	return (p);
}

int			if_is_u(t_param *p)
{
	char					*s;
	unsigned long long int	un_int;

	un_int = (unsigned long long int)p->arg;
	if (p->conv == 'u' || p->conv == 'U')
	{
		if (p->conv == 'U')
			p->l = 1;
		if (p->j == 1 || p->z == 1)
			s = ft_ulitoa((unsigned long long int)un_int);
		else if (p->ll == 1)
			s = ft_ulitoa((unsigned long long int)un_int);
		else if (p->l == 1)
			s = ft_ulitoa((unsigned long int)un_int);
		else if (p->hh == 1)
			s = ft_uitoa((unsigned char)un_int);
		else if (p->h == 1)
			s = ft_uitoa((unsigned short int)un_int);
		else
			s = ft_uitoa((unsigned int)un_int);
		s = add_flags(p, s);
		p = tool_if_is_u(p, s);
		return (1);
	}
	return (0);
}
