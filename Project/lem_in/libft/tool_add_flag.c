/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_add_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:58:50 by jclaudan          #+#    #+#             */
/*   Updated: 2017/03/13 23:07:07 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*tool_add_flag(t_param *p, char *s, char *tp, size_t len)
{
	if (p->less == 1 && s[0] != '-')
		len = len + 1;
	if (s[0] == '-' && p->precis != 0)
		tp = set_char(' ', (p->champ - (len + 1)));
	if (s[0] == '-' && p->precis == 0)
		tp = set_char(' ', (p->champ - len));
	else if (!(s[0] == '-') && p->precis == 0)
		tp = set_char(' ', (p->champ - len));
	else if (!(s[0] == '-') && p->precis != 0)
		tp = set_char(' ', (p->champ - len));
	if (p->plus == 1 && p->less == 0)
		tp[p->champ - len - 1] = '+';
	if (p->plus == 1 && p->less == 1)
		tp = kit_add_flag(p, s, tp, p->str1);
	if (p->less == 1 && p->plus == 0)
	{
		tp = ft_strjoin_f(s, tp, 3);
		tp = ft_strjoin_f((set_char(' ', 1)), tp, 3);
		return (tp);
	}
	else
		return (ft_strjoin_f(tp, s, 3));
	return (tp);
}

char	*tool_add_flag_1(t_param *p, char *s, char *tp, size_t len)
{
	if (p->plus == 1 && p->less == 1 && s[0] != '-')
		len = len + 1;
	if (p->plus == 0 && p->less == 1 && p->zero == 0)
		len = len - 1;
	tp = set_char(' ', (p->champ - len - 1));
	if (p->precis != 0 && (size_t)p->precis == len && s[0] == '-')
		return (mini_kit_add_flag_1(s, tp));
	else if (p->space == 1)
		return (kit_add_flag_1(p, s, tp));
	if ((p->conv == 'x' || p->conv == 'X') && p->less == 1 && p->hasht == 1)
		tp = set_char(' ', (p->champ - len - 2));
	else
		tp = set_char(' ', (p->champ - len));
	tp = ft_strjoin_f(s, tp, 2);
	if (p->plus == 1)
	{
		if (oxu1(p) == 1)
			tp = ft_strjoin_f(tp, " ", 1);
		else
			tp = ft_strjoin_f("+", tp, 2);
	}
	return (tp);
}

char	*tool_add_flag_2(t_param *p, char *tp, size_t len, char *s)
{
	if (p->precis != 0 && not_in_list(p->conv) == 0)
		return (kit_add_flag_2(p, tp, len, s));
	else
	{
		if (mini_condition_2(p) == 1)
			tp = set_char('0', (p->champ - len));
		return (mini_tool_add_flag_2(p, tp, len, s));
	}
}

char	*tool_add_flag_3(t_param *p, char *tp, size_t len, char *s)
{
	if (p->plus == 1)
	{
		if (s[0] != '-')
		{
			tp = set_char(' ', (p->champ - len));
			if (oxu1(p) == 1)
				tp[p->champ - len - 1] = ' ';
			else
				tp[p->champ - len - 1] = '+';
			if (p->less == 1)
			{
				tp = ft_strjoin_f(s, tp, 3);
				tp[p->champ - 1] = '\0';
				return (ft_strjoin_f("+", tp, 2));
			}
			else
				return (ft_strjoin_f(tp, s, 3));
		}
		else
			return (kit_add_flag_3(tp, len, s, p));
	}
	if (p->less == 1 && p->space == 0)
		return (micro_kit_add_flag_3(p, s, tp, len));
	return (s);
}

char	*tool_add_flag_4(t_param *p, char *tp, size_t len, char *s)
{
	if (p->precis != 0 && (size_t)p->precis == len && s[0] == '-')
		return (kit_add_flag_4(tp, len, s));
	else if ((size_t)p->precis == len)
		tp = set_char(' ', (p->champ - len));
	else
	{
		if ((p->conv == 'x' || p->conv == 'X') && p->precis != 0)
			tp = set_char(' ', (p->champ - len));
		else
			tp = set_char('0', (p->champ - len));
	}
	if ((size_t)p->precis == len && p->plus == 1 && oxu2(p) == 1)
		tp[p->champ - len - 1] = '+';
	if (p->plus == 1 && (size_t)p->precis != len && s[0] != '-' && oxu2(p) == 1)
		tp[0] = '+';
	if (p->plus == 1 && (size_t)p->precis != len && s[0] == '-')
	{
		s[0] = '0';
		tp = set_char('0', (p->champ - len));
		tp[0] = '-';
	}
	if (p->space == 1 && p->plus == 0)
		tp[0] = ' ';
	return (ft_strjoin_f(tp, s, 3));
}
