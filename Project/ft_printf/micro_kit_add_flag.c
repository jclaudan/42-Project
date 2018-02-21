/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_kit_add_flag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:22:27 by jclaudan          #+#    #+#             */
/*   Updated: 2017/03/13 21:38:25 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*micro_kit_add_flag_3(t_param *p, char *s, char *tp, size_t len)
{
	if (p->conv == 'o' && p->hasht == 1)
	{
		tp = ft_strjoin_f(s, set_char(' ', (p->champ - len - 1)), 3);
		return (ft_strjoin_f("0", tp, 2));
	}
	return (ft_strjoin_f(s, tp = set_char(' ', (p->champ - len)), 2));
}

char		*micro_kit_add_flag(t_param *p, char *tp, size_t len)
{
	if (p->hasht == 1 && (p->conv == 'X' || p->conv == 'x'))
		tp = set_char(' ', (p->champ - len - 2));
	else
		tp = set_char(' ', (p->champ - len));
	if (p->conv == 'o' && p->hasht == 1)
		tp[p->champ - len - 1] = '0';
	return (tp);
}

char		*micro_kit_add_flag_2(t_param *p, char *s, char *tp)
{
	if ((p->conv == 'o' || p->conv == 'O') && p->hasht == 1)
	{
		s[0] = '0';
		s[1] = '\0';
		return (ft_strjoin_f(tp, s, 3));
	}
	return (ft_strjoin_f(tp, "", 1));
}

int			mini_condition_1(t_param *p, char *s)
{
	if (p->plus == 0 && p->space == 1 && s[0] != '-'
			&& oxu2(p) == 1 && not_in_list(p->conv) == 0)
		return (1);
	return (0);
}

t_param		*init_t_param(t_param *p)
{
	p = set_champ(p);
	p = set_precis(p);
	p = set_conv(p);
	return (p);
}
