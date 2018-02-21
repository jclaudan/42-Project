/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_is_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:33:59 by jclaudan          #+#    #+#             */
/*   Updated: 2017/03/13 21:53:38 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			not_in_list(char c)
{
	if (!ft_strchr("sSpdDioOuUxXcC%#-+ hljz0123456789.*", c))
	{
		return (1);
	}
	return (0);
}

void		if_is_d_kit(t_param *p, char *s)
{
	s = add_flags(p, s);
	p->size += ft_strlen_p(s);
	ft_putstr(s);
	ft_memdel((void*)&s);
}

char		*if_is_d_kit2(t_param *p, char *s, long long int long_int)
{
	if (p->j == 1)
		s = ft_litoa((long long int)long_int);
	else if (p->z == 1)
		s = ft_litoa((size_t)long_int);
	else if (p->hh == 1 && p->conv != 'D')
		s = ft_litoa((char)long_int);
	else if (p->hh == 1 && p->conv == 'D')
		s = ft_litoa((unsigned short int)long_int);
	else if (p->ll == 1)
		s = ft_litoa((long long int)long_int);
	else if (p->h == 1 && p->conv != 'D')
		s = ft_litoa((short int)long_int);
	else if (p->h == 1 && p->conv == 'D')
		s = ft_litoa((unsigned short int)long_int);
	else if (p->l == 1 || (p->h == 0 && p->conv == 'D'))
		s = ft_litoa((long int)long_int);
	else
		s = ft_litoa((int)long_int);
	return (s);
}

int			if_is_d(t_param *p)
{
	char			*s;
	long long int	long_int;

	long_int = (long long int)p->arg;
	s = NULL;
	if (p->conv == 'd' || p->conv == 'i' || p->conv == 'D')
	{
		s = if_is_d_kit2(p, s, long_int);
		if_is_d_kit(p, s);
		return (1);
	}
	return (0);
}
