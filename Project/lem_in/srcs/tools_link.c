/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:39:56 by jclaudan          #+#    #+#             */
/*   Updated: 2017/05/25 14:35:55 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char	*get_link(char *room, char *link)
{
	char **info;
	char *ret;

	ret = NULL;
	info = ft_strsplit(link, '-');
	if (!ft_strcmp(info[0], room))
		ret = ft_strdup(info[1]);
	else if (!ft_strcmp(info[1], room))
		ret = ft_strdup(info[0]);
	return (ret);
}

t_obj	*save_line(t_obj *room)
{
	t_obj *tp;

	tp = room;
	while (tp)
	{
		tp->save = ft_strdup(tp->line);
		tp = tp->nxt;
	}
	return (room);
}

int		count_link(char *room, t_obj *link)
{
	int		count;
	char	**tab;

	count = 0;
	while (link)
	{
		tab = ft_strsplit(link->line, '-');
		if (!ft_strcmp(room, tab[0]) || !ft_strcmp(tab[1], room))
			++count;
		link = link->nxt;
	}
	return (count);
}

t_obj	*create_link(t_obj *room, t_obj *link)
{
	t_obj	*tmp;
	t_obj	*tmp2;
	char	**tp_link;
	int		n;

	tmp = link;
	tmp2 = room;
	while (tmp2)
	{
		link = tmp;
		n = count_link(tmp2->line, link);
		if (!(tmp2->link = (char**)malloc(sizeof(char*) * n + 1)))
			return (0);
		tmp2->link[n] = NULL;
		while (link && n)
		{
			tp_link = ft_strsplit(link->line, '-');
			if (!ft_strcmp(tmp2->line, tp_link[0]) ||
			!ft_strcmp(tp_link[1], tmp2->line))
				tmp2->link[--n] = get_link(tmp2->line, link->line);
			link = link->nxt;
		}
		tmp2 = tmp2->nxt;
	}
	return (room);
}
