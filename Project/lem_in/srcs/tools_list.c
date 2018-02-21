/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:39:06 by jclaudan          #+#    #+#             */
/*   Updated: 2017/05/25 14:36:36 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_obj	*new_link(char *room, char *prev)
{
	t_obj *link;

	if (!(link = (t_obj*)malloc(sizeof(t_obj))))
		exit(0);
	link->line = room;
	link->prev = prev;
	link->nxt = NULL;
	return (link);
}

t_obj	*add_link(t_obj *link, char *room, char *prev)
{
	t_obj *tp;

	tp = link;
	if (!link->line)
	{
		link = new_link(room, prev);
		return (link);
	}
	else
	{
		while (tp->nxt != NULL)
			tp = tp->nxt;
		tp->nxt = new_link(room, prev);
	}
	return (link);
}

t_obj	*init_lst(void)
{
	t_obj *lst;

	if (!(lst = (t_obj*)malloc(sizeof(t_obj*))))
		exit(0);
	lst->line = NULL;
	lst->start = 0;
	lst->end = 0;
	lst->save = NULL;
	lst->nxt = NULL;
	return (lst);
}

t_obj	*new_lst(char *line, int start, int end)
{
	t_obj *room;

	if (!(room = malloc(sizeof(t_obj))))
		exit(0);
	room->line = ft_strdup(line);
	room->nxt = NULL;
	room->start = start;
	room->end = end;
	return (room);
}

t_obj	*add_lst(t_obj *room, char *line, int start, int end)
{
	t_obj *tmp;

	tmp = room;
	if (!room->line)
	{
		room = new_lst(line, start, end);
		return (room);
	}
	else
	{
		while (tmp->nxt != NULL)
			tmp = tmp->nxt;
		tmp->nxt = new_lst(line, start, end);
	}
	return (room);
}
