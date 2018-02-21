/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_condition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:21:17 by jclaudan          #+#    #+#             */
/*   Updated: 2017/03/13 21:48:52 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		oxu1(t_param *p)
{
	if (p->conv == 'o' || p->conv == 'O' || p->conv == 'x' || p->conv == 'X'
			|| p->conv == 'u' || p->conv == 'U')
		return (1);
	else
		return (0);
}

int		oxu2(t_param *p)
{
	if (p->conv != 'o' && p->conv != 'O' && p->conv != 'x' && p->conv != 'X'
			&& p->conv != 'u' && p->conv != 'U'
			&& p->conv != 's' && p->conv != 'S' && p->conv != 'p')
		return (1);
	else
		return (0);
}

int		oxu3(t_param *p)
{
	if (p->conv != 'x' && p->conv != 'X' && p->ll != 1 && p->conv != 'o'
			&& p->conv != 'O' && p->conv != 'd' && p->conv != 'D'
			&& p->conv != 'i' && p->conv != 'u' && p->conv != 'U'
			&& p->conv != 'p')
		return (1);
	else
		return (0);
}

int		oxu4(t_param *p)
{
	if (p->conv == 'x' || p->conv == 'X' || p->conv == 'o'
	|| p->conv == 'd' || p->conv == 'i')
	{
		if (p->wildcard_p == 1 || p->wildcard_f == 1)
		{
			return (0);
		}
		return (1);
	}
	else
		return (0);
}

int		mini_condition_2(t_param *p)
{
	if (p->conv == 'o' || p->conv == 'd' || p->conv == 'i'
			|| p->conv == 'u' || not_in_list(p->conv) == 1 || p->conv == 's'
			|| p->conv == 'c')
		return (1);
	return (0);
}
