/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_is_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:33:16 by jclaudan          #+#    #+#             */
/*   Updated: 2017/03/13 21:58:08 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			if_is_s_kit(t_param *p, char *s)
{
	s = add_flags(p, s);
	ft_putstr(s);
	p->size += ft_strlen_p(s);
}

int				if_is_s(t_param *p)
{
	char	*s;

	s = (char*)p->arg;
	if (p->conv == 's' || p->conv == 'S')
	{
		if (p->ll == 1 || p->j == 1 || p->z == 1)
			return (0);
		if (s == NULL)
			s = ft_strdup("(null)");
		if (p->l == 1 || p->conv == 'S')
		{
			p = conv_str_unicode((wchar_t*)p->arg, p);
			if ((wchar_t*)p->arg == 0)
				p->size += ft_strlen_p(p->str2);
			if (!(ft_strchr(p->str_p, '.') && p->precis == 0))
				ft_putstr(p->str2);
			return (1);
		}
		else
		{
			if_is_s_kit(p, s);
			return (1);
		}
	}
	return (0);
}

t_param			*tool_if_is_o(t_param *p, char *s)
{
	if (p->hasht == 1 && (long long int)p->arg != 0
			&& p->precis == 0 && p->champ == 0)
		s = ft_strjoin_f("0", s, 2);
	ft_putstr(s);
	p->size += ft_strlen_p(s);
	ft_memdel((void*)&s);
	return (p);
}

int				if_is_o(t_param *p)
{
	char					*s;
	unsigned long long int	un_int;

	un_int = (unsigned long long int)p->arg;
	if (p->conv == 'o' || p->conv == 'O')
	{
		if (un_int == 0)
			s = ft_strdup("0");
		if (p->j == 1 || p->z == 1)
			s = ft_olitoa((unsigned long long int)un_int);
		else if (p->ll == 1)
			s = ft_olitoa((unsigned long long int)un_int);
		else if (p->l == 1 || p->conv == 'O')
			s = ft_olitoa((unsigned long int)un_int);
		else if (p->hh == 1)
			s = ft_oitoa((unsigned char)un_int);
		else if (p->h == 1)
			s = ft_oitoa((unsigned short int)un_int);
		else
			s = ft_oitoa((unsigned int)un_int);
		s = add_flags(p, s);
		p = tool_if_is_o(p, s);
		return (1);
	}
	return (0);
}

int				if_is_p(t_param *p)
{
	char			*s;
	size_t			un_int;

	un_int = (long long int)p->arg;
	if (p->conv == 'p')
	{
		s = ft_hitoa((size_t)un_int, 'x');
		s = ft_strjoin_f("0x", s, 2);
		if (!(ft_strchr(p->str_p, '.')) && p->precis == 0)
		{
			s = add_flags(p, s);
		}
		else if (p->precis != 0)
		{
			s = ft_strjoin_f("0x", set_char('0', p->precis), 2);
		}
		else
			s = ft_strjoin_f("0x", "", 0);
		p->size += ft_strlen_p(s);
		ft_putstr(s);
		ft_memdel((void*)&s);
		return (1);
	}
	return (0);
}
