/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:38:47 by jclaudan          #+#    #+#             */
/*   Updated: 2017/05/25 14:26:04 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int				check_room(char *line)
{
	char	**tab;
	int		i;
	size_t	len;

	tab = ft_strsplit(line, ' ');
	len = ft_strlen_p(line) - 1;
	if (line[len] == ' ')
		return (0);
	if (ft_size_tab(tab) != 3)
		return (0);
	else if (tab[0][0] == 'L')
		return (0);
	i = -1;
	while (tab[1][++i])
		if (!ft_isdigit(tab[1][i]))
			return (0);
	i = -1;
	while (tab[2][++i])
		if (!ft_isdigit(tab[2][i]))
			return (0);
	return (1);
}

int				check_visit(t_obj *visit, char *room)
{
	while (visit)
	{
		if (!ft_strcmp(visit->line, room))
			return (1);
		visit = visit->nxt;
	}
	return (0);
}

int				check_link(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (line[0] == 'L')
		return (0);
	else if (line[0] == '-')
		return (0);
	else if (line[len - 1] == '-')
		return (0);
	else if (ft_strchr(line, ' '))
		return (0);
	line = ft_strchr(line, '-');
	if (line[1] == 'L')
		return (0);
	return (1);
}

int				check_lst(t_obj *room, char *name)
{
	int		i;
	char	**tab;

	while (room != NULL)
	{
		i = 0;
		tab = ft_strsplit(room->line, ' ');
		room->line = tab[0];
		if (!ft_strcmp(name, room->line))
			return (1);
		else
			room = room->nxt;
	}
	return (0);
}

int				check_name(t_obj *room, t_obj *link)
{
	int		i;
	char	*room1;
	char	*room2;

	if (!room->line || !link->line)
		return (0);
	while (link != NULL)
	{
		i = 0;
		while (link->line[i] != '-' && link->line[i])
			++i;
		room1 = ft_strsub(link->line, 0, i);
		room2 = link->line + i + 1;
		if (!ft_strcmp(room1, room2))
			return (0);
		if (!check_lst(room, room1))
			return (0);
		if (!check_lst(room, room2))
			return (0);
		link = link->nxt;
	}
	return (1);
}
