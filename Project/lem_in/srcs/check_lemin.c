/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lemin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:38:58 by jclaudan          #+#    #+#             */
/*   Updated: 2017/05/25 14:29:31 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		check_if_dble(t_obj *room)
{
	t_obj	*tmp;
	t_obj	*tmp2;
	int		i;

	tmp = room;
	tmp2 = room;
	while (tmp)
	{
		room = tmp2;
		i = 0;
		while (room)
		{
			if (!ft_strcmp(room->line, tmp->line) && !i)
				++i;
			else if (!ft_strcmp(room->line, tmp->line) && i)
				return (0);
			room = room->nxt;
		}
		tmp = tmp->nxt;
	}
	return (1);
}

int		check_start_end(t_obj *room)
{
	int start;
	int	end;

	start = 0;
	end = 0;
	while (room)
	{
		if (room->start)
			++start;
		if (room->end)
			++end;
		room = room->nxt;
	}
	if (end != 1 || start != 1)
		return (0);
	return (1);
}

t_obj	*nxt_antz(t_obj *path)
{
	path->nxt->antz = path->antz;
	return (path);
}

t_obj	*add_link_prv(t_obj *path)
{
	t_obj *tp;

	tp = path;
	while (tp)
	{
		if (tp->nxt)
		{
			tp->nxt->prv = tp;
		}
		tp = tp->nxt;
	}
	return (path);
}

t_obj	*init_antz(t_obj *path)
{
	t_obj *tp;

	tp = path;
	while (tp)
	{
		tp->antz = 0;
		tp = tp->nxt;
	}
	return (path);
}
