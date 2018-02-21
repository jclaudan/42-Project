/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:39:21 by jclaudan          #+#    #+#             */
/*   Updated: 2017/05/25 14:34:04 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char	*get_com(char **line)
{
	char	*str;

	str = NULL;
	str = ft_strjoin_f(str, "\n", 0);
	while (get_next_line(0, line) > 0)
	{
		if (*line[0] == '#')
		{
			str = ft_strjoin_f(str, *line, 0);
			str = ft_strjoin_f(str, "\n", 0);
			continue ;
		}
		else
			break ;
	}
	return (str);
}

t_obj	*moove_antz(t_obj *path, int antz, int nb)
{
	t_obj *moove;

	moove = path;
	if (antz <= nb)
		path->antz = antz;
	path = go_last_antz(path);
	while (path)
	{
		path = nxt_antz(path);
		path = path->prv;
	}
	return (moove);
}

int		check_end(t_obj *path, int nb)
{
	while (path->nxt)
		path = path->nxt;
	if (path->antz == nb)
		return (1);
	else
		return (0);
}

void	display_antz_moove(t_obj *path)
{
	while (path->nxt)
		path = path->nxt;
	while (path->prv)
	{
		if (path->antz)
		{
			if (path->nxt)
				if (path->nxt->antz != path->antz)
					ft_printf("L%d-%s ", path->antz, path->line);
			if (!path->nxt)
				ft_printf("L%d-%s ", path->antz, path->line);
		}
		path = path->prv;
	}
	ft_printf("\n");
}

void	make_lemin(t_obj *path, int nb)
{
	int antz;

	antz = 1;
	path = init_antz(path);
	path = add_link_prv(path);
	ft_printf("\n");
	while (!check_end(path, nb))
	{
		path = moove_antz(path, antz, nb);
		display_antz_moove(path);
		++antz;
	}
}
