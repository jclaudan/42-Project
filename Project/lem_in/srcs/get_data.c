/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:39:37 by jclaudan          #+#    #+#             */
/*   Updated: 2017/05/25 15:42:39 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		get_nb_antz(char **str)
{
	char	*line;
	int		i;

	i = -1;
	line = NULL;
	while (1)
	{
		if (get_next_line(0, &line) <= 0)
			return (0);
		if (line[0] == '#')
		{
			*str = ft_strjoin_f(*str, line, 0);
			*str = ft_strjoin_f(*str, "\n", 0);
		}
		else
			break ;
	}
	if (!line)
		return (0);
	while (line[++i])
		if (!ft_isdigit(line[i]))
			return (0);
	*str = ft_strjoin_f(*str, line, 0);
	*str = ft_strjoin_f(*str, "\n", 0);
	return (ft_atoi(line));
}

int		insert_data(char *line, t_obj **room, t_obj **link, char **str)
{
	if (line[0] == '#')
	{
		*str = ft_strjoin_f(*str, check_com(line, room), 0);
		*str = ft_strjoin_f(*str, "\n", 0);
		return (1);
	}
	else if (ft_strchr(line, '-'))
	{
		if (check_link(line))
		{
			*str = ft_strjoin_f(*str, check_com(line, room), 0);
			*str = ft_strjoin_f(*str, "\n", 0);
			*link = add_lst(*link, line, 0, 0);
			return (1);
		}
	}
	else
	{
		if (check_room(line))
		{
			*room = add_lst(*room, line, 0, 0);
			return (1);
		}
	}
	return (0);
}

char	*get_data(t_obj **room, t_obj **link, char **str)
{
	char *line;
	char *str_tp;

	line = NULL;
	str_tp = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strlen_p(line))
			return (NULL);
		str_tp = ft_strjoin_f(str_tp, line, 0);
		str_tp = ft_strjoin_f(str_tp, "\n", 0);
		if (!insert_data(line, room, link, &str_tp))
			return (NULL);
	}
	*str = ft_strjoin_f(*str, str_tp, 0);
	return ("OK");
}

int		check_data(t_obj *room, t_obj *link, int n)
{
	if (!check_name(room, link) || !check_if_dble(room) ||
	!check_start_end(room) || n <= 0)
	{
		ft_printf("ERROR\n");
		return (0);
	}
	else
	{
		return (1);
	}
}

int		main(void)
{
	int		nb;
	t_obj	*room;
	t_obj	*link;
	t_all	path;

	room = init_lst();
	link = init_lst();
	if ((nb = get_nb_antz(&path.str)) <= 0)
		return (ft_printf("ERROR\n"));
	if (!get_data(&room, &link, &path.str))
		return (ft_printf("ERROR\n"));
	if (!check_data(room, link, nb))
		return (0);
	room = save_line(room);
	room = create_link(room, link);
	path.path1 = find_path(room);
	path.path2 = make_path(path.path1);
	if (check_path(path.path1, room, link))
	{
		ft_disp_tab_char(ft_strsplit(path.str, '\n'));
		make_lemin(path.path2, nb);
		return (1);
	}
	ft_printf("ERROR\n");
	return (0);
}
