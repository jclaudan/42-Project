/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kit_add_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:04:33 by jclaudan          #+#    #+#             */
/*   Updated: 2017/03/13 22:59:16 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*kit_add_flag(t_param *p, char *s, char *tp, char *str)
{
	if (p->space == 1 && s[0] == '-' && p->precis != 0)
	{
		s[0] = '0';
		s = ft_strjoin_f("-", s, 2);
		tp = ft_strjoin_f(s, tp, 3);
	}
	else
		tp = ft_strjoin_f(s, tp, 3);
	if (s[0] == '-')
		tp = ft_strjoin_f(str, tp, 3);
	else
	{
		if (oxu1(p) == 1)
			tp = ft_strjoin_f(tp, set_char(' ', 1), 3);
		else
			tp = ft_strjoin_f(set_char('+', 1), tp, 3);
	}
	return (tp);
}

char	*kit_add_flag_1(t_param *p, char *s, char *tp)
{
	tp = ft_strjoin_f(s, tp, 3);
	if (oxu1(p) == 1)
		tp = ft_strjoin_f(tp, set_char(' ', 1), 3);
	else
		tp = ft_strjoin_f(set_char(' ', 1), tp, 3);
	return (tp);
}

char	*kit_add_flag_2(t_param *p, char *tp, size_t len, char *s)
{
	if (p->plus == 1 && s[0] != '-')
	{
		tp = set_char(' ', (p->champ - len));
		if (oxu1(p) == 1)
			tp[p->champ - len - 1] = ' ';
		else
			tp[p->champ - len - 1] = '+';
	}
	else if (s[0] == '-' && p->plus == 0 && p->conv != 'x' && p->conv != 'X')
	{
		tp = set_char(' ', (p->champ - len - 1));
		s[0] = '0';
		tp[p->champ - len - 1] = '-';
	}
	else if (s[0] == '-' && p->plus == 1)
	{
		tp = set_char(' ', (p->champ - len));
		return (tp = ft_strjoin_f(tp, s, 1));
	}
	else if (p->conv == 'x' || p->conv == 'X')
		tp = set_char(' ', (p->champ - len));
	else if (p->conv == 'd' || p->conv == 'i')
		tp = set_char(' ', (p->champ - len));
	return (ft_strjoin_f(tp, s, 3));
}

char	*kit_add_flag_3(char *tp, size_t len, char *s, t_param *p)
{
	tp = set_char(' ', (p->champ - len - 1));
	s[0] = '0';
	s = ft_strjoin_f("-", s, 2);
	return (ft_strjoin_f(tp, s, 3));
}

char	*kit_add_flag_4(char *tp, size_t len, char *s)
{
	len = len - 1;
	s[0] = '0';
	s = ft_strjoin_f("-", s, 2);
	tp = set_char(' ', len);
	tp = ft_strjoin_f(tp, s, 3);
	return (tp);
}
