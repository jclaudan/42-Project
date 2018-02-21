/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:39:48 by jclaudan          #+#    #+#             */
/*   Updated: 2017/05/25 15:31:53 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_obj	*go_to_room(t_obj *room, char *name)
{
	while (room)
	{
		if (!ft_strcmp(room->line, name))
			return (room);
		room = room->nxt;
	}
	return (room);
}

t_obj	*go_to_start(t_obj *room)
{
	while (room)
	{
		if (room->start)
			return (room);
		room = room->nxt;
	}
	return (room);
}

t_obj	*go_to_end(t_obj *room)
{
	while (room)
	{
		if (room->end)
			return (room);
		room = room->nxt;
	}
	return (room);
}

t_obj	*go_last_antz(t_obj *path)
{
	while (path->nxt->nxt)
	{
		if (!path->nxt->antz)
			return (path);
		path = path->nxt;
	}
	return (path);
}

void	join_str(char **str, char *line)
{
	*str = ft_strjoin_f(*str, line, 0);
	*str = ft_strjoin_f(*str, "\n", 0);
}
