/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_kit_add_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:08:59 by jclaudan          #+#    #+#             */
/*   Updated: 2017/03/13 21:48:16 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*mini_kit_add_flag(t_param *p, char *s)
{
	if (p->conv == 'x' && (long long int)p->arg != 0)
		s = ft_strjoin_f("0x", s, 2);
	if (p->conv == 'X' && (long long int)p->arg != 0)
		s = ft_strjoin_f("0X", s, 2);
	return (s);
}

char	*mini_kit_add_flag_1(char *s, char *tp)
{
	s[0] = '0';
	s = ft_strjoin_f("-", s, 2);
	tp = ft_strjoin_f(s, tp, 3);
	return (tp);
}

char	*mini_kit_add_flag_2(t_param *p, char *tp, size_t len)
{
	if (p->hasht == 1)
	{
		if (p->conv == 'x')
			tp = ft_strjoin_f("0x", set_char('0', (p->champ - len - 2)), 2);
		if (p->conv == 'X')
			tp = ft_strjoin_f("0X", set_char('0', (p->champ - len - 2)), 2);
	}
	else
		tp = set_char('0', (p->champ - len));
	return (tp);
}

char	*mini_tool_add_flag_2(t_param *p, char *tp, size_t len, char *s)
{
	if (p->plus == 1 && s[0] != '-')
		tp[0] = '+';
	if (s[0] == '-')
	{
		s[0] = '0';
		tp = set_char('0', (p->champ - len));
		tp[0] = '-';
	}
	else if (len == 1 && s[0] == '0')
	{
		len = len - 1;
		if (p->conv == 'S' || (p->conv == 'd' && !(ft_strchr(p->form, '.'))))
		{
			tp = set_char('0', (p->champ - len));
			if (p->plus == 1 && p->conv == 'd')
				tp[0] = '+';
		}
		else
			tp = set_char(' ', (p->champ - len));
		s[0] = '\0';
	}
	else if (p->conv == 'x' || p->conv == 'X')
		tp = mini_kit_add_flag_2(p, tp, len);
	return (ft_strjoin_f(tp, s, 3));
}

char	*mini_kit_add_flag_3(char *tp, t_param *p, char *s)
{
	tp = set_char(' ', 1);
	if (p->plus == 1)
		tp[0] = '+';
	if (p->space == 1 && p->plus == 0)
		tp[0] = ' ';
	tp = ft_strjoin_f(tp, s, 3);
	return (tp);
}
