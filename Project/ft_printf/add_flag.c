/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:40:26 by jclaudan          #+#    #+#             */
/*   Updated: 2017/03/13 22:51:49 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*add_flags(t_param *p, char *s)
{
	size_t	len;
	char	*tp;
	char	*tp_s;

	tp = NULL;
	tp_s = NULL;
	len = ft_strlen_p(s);
	if (ft_strchr(p->str_p, '.') && (size_t)p->precis < len && p->conv == 's')
	{
		s = ft_strsub(s, 0, p->precis);
		len = ft_strlen_p(s);
	}
	if (p->precis != 0 && (size_t)p->precis > len && not_in_list(p->conv) == 0)
	{
		s = add_flags_4(p, s, tp, len);
		len = ft_strlen_p(s);
	}
	if (p->champ != 0 && (size_t)p->champ > len)
		return (add_flags_1(p, s, tp, len));
	if (p->champ != 0 && (size_t)p->champ <= len)
		return (add_flags_3(p, s, tp));
	else if (p->champ == 0)
		return (add_flags_2(p, s, tp, len));
	return (s);
}

char		*add_flags_1(t_param *p, char *s, char *tp, size_t len)
{
	if (p->zero == 1 && p->less == 1)
		return (tool_add_flag_1(p, s, tp, len));
	if (p->zero == 1 && p->space == 1)
		return (tool_add_flag_4(p, tp, len, s));
	else if (p->space == 1 && p->zero == 0)
		return (tool_add_flag(p, s, tp, len));
	else if (p->space == 0 && p->zero == 1)
		return (tool_add_flag_2(p, tp, len, s));
	else if (p->plus == 1 || p->less == 1)
		return (tool_add_flag_3(p, tp, len, s));
	else if ((p->conv == 'X' || p->conv == 'x') && p->hasht == 1)
	{
		s = mini_kit_add_flag(p, s);
		if ((long long int)p->arg == 0)
			return (set_char(' ', (p->champ - len + 1)));
	}
	else if ((long long int)p->arg == 0 && oxu4(p) == 1)
		return (ft_strjoin_f(tp = set_char(' ', (p->champ - len)), " ", 1));
	tp = micro_kit_add_flag(p, tp, len);
	return (ft_strjoin_f(tp, s, 1));
}

char		*add_flags_2(t_param *p, char *s, char *tp, size_t len)
{
	if (p->zero == 1 && p->space == 1 && s[0] != '-' && oxu2(p) == 1)
		return (mini_kit_add_flag_3(tp, p, s));
	else
	{
		if (p->plus == 1 && s[0] != '-' && oxu2(p) == 1)
			tp = set_char('+', 1);
		else if (mini_condition_1(p, s))
			tp = set_char(' ', 1);
		else if ((p->conv == 'x' || p->conv == 'X') && p->hasht == 1)
		{
			if (p->conv == 'x' && (long long int)p->arg != 0)
				s = ft_strjoin_f("0x", s, 2);
			if (p->conv == 'X' && (long long int)p->arg != 0)
				s = ft_strjoin_f("0X", s, 2);
		}
		else if (len == 1 && s[0] == '0' && oxu3(p) == 1)
			s[0] = '\0';
		if ((long long)p->arg == 0 && ft_strchr(p->form, '.') && p->precis == 0)
			tp = micro_kit_add_flag_2(p, s, tp);
		else if (!tp)
			return (s);
		else
			tp = ft_strjoin_f(tp, s, 3);
	}
	return (tp);
}

char		*add_flags_3(t_param *p, char *s, char *tp)
{
	if (p->plus == 1 && s[0] != '-' && oxu2(p) == 1)
		return (ft_strjoin_f("+", s, 2));
	else if (p->plus == 1 && s[0] == '-')
	{
		if (p->precis != 0)
		{
			s[0] = '0';
			return (tp = ft_strjoin_f("-", s, 2));
		}
		else
			return (s);
	}
	return (s);
}

char		*add_flags_4(t_param *p, char *s, char *tp, size_t len)
{
	char	*tp_s;

	tp_s = NULL;
	if (s[0] == '-' && p->conv != 's')
	{
		s[0] = '0';
		tp = set_char('0', p->precis - len);
		tp = ft_strjoin_f("-", tp, 2);
		return (ft_strjoin_f(tp, s, 3));
	}
	else
	{
		if (p->conv == 's')
		{
			return (s);
		}
		else
			tp_s = set_char('0', p->precis - len);
		return (ft_strjoin_f(tp_s, s, 3));
	}
}
