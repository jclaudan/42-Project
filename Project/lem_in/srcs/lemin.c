/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:39:30 by jclaudan          #+#    #+#             */
/*   Updated: 2017/05/25 15:50:34 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char	*check_com(char *line, t_obj **room)
{
	char	*str;

	if (!ft_strcmp("##end", line))
	{
		str = get_com(&line);
		if (check_room(line))
		{
			join_str(&str, line);
			*room = add_lst(*room, line, 0, 1);
			return (str);
		}
		return (str);
	}
	else if (!ft_strcmp("##start", line))
	{
		str = get_com(&line);
		if (check_room(line))
		{
			join_str(&str, line);
			*room = add_lst(*room, line, 1, 0);
			return (str);
		}
		return (str);
	}
	return (NULL);
}

t_obj	*add_in_first(t_obj *path, char *room)
{
	t_obj *tmp;

	if (!path->line)
	{
		path = new_lst(room, 0, 0);
		return (path);
	}
	else
	{
		tmp = new_lst(room, 0, 0);
		tmp->nxt = path;
	}
	return (tmp);
}

t_obj	*find_path(t_obj *room)
{
	t_obj	*path;
	t_obj	*start;
	t_obj	*tmp1;
	t_obj	*tmp2;
	int		i;

	path = (t_obj*)malloc(sizeof(t_obj));
	start = go_to_start(room);
	path = add_link(path, start->line, NULL);
	tmp1 = path;
	tmp2 = room;
	while (path)
	{
		tmp2 = go_to_room(room, path->line);
		i = -1;
		while (tmp2->link[++i])
		{
			if (!check_visit(tmp1, tmp2->link[i]))
				tmp1 = add_link(tmp1, tmp2->link[i], path->line);
		}
		if (tmp2->end)
			path->nxt = NULL;
		path = path->nxt;
	}
	return (tmp1);
}

int		check_path(t_obj *path, t_obj *room, t_obj *link)
{
	while (link)
	{
		if (!link->line)
			return (0);
		link = link->nxt;
	}
	while (path->nxt)
		path = path->nxt;
	room = go_to_end(room);
	if (!ft_strcmp(room->line, path->line))
		return (1);
	else
		return (0);
}

t_obj	*make_path(t_obj *path)
{
	t_obj	*path2;
	t_obj	*tmp;
	t_obj	*tmp2;
	char	*prev;

	path2 = (t_obj*)malloc(sizeof(t_obj));
	tmp = path;
	while (tmp->nxt)
		tmp = tmp->nxt;
	path2 = add_in_first(path2, tmp->line);
	prev = tmp->prev;
	while (prev)
	{
		tmp2 = go_to_room(path, prev);
		path2 = add_in_first(path2, tmp2->line);
		prev = tmp2->prev;
	}
	return (path2);
}
