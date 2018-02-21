/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:44:05 by jclaudan          #+#    #+#             */
/*   Updated: 2017/05/17 21:06:10 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	init_pos_null(t_pos *pos)
{
	pos->y = 0;
	pos->x = 0;
}

void		recup_arena(char *line, t_obj *e)
{
	t_pos		pos;
	int			i;

	i = 8;
	init_pos_null(&pos);
	while (!ft_isdigit(line[i]))
		++i;
	while (ft_isdigit(line[i]))
		pos.y = pos.y * 10 + (line[i++] - '0');
	e->mform = (char **)malloc((sizeof(char *)) * (pos.y + 2));
	e->mform[pos.y + 1] = NULL;
	while (ft_isdigit(line[++i]))
		pos.x = pos.x * 10 + (line[i] - '0');
	get_next_line(0, &line) <= 0 ? exit(0) : 0;
	i = -1;
	e->m.x = pos.x;
	e->m.y = pos.y;
	while (++i <= pos.y)
	{
		get_next_line(0, &line) <= 0 ? exit(0) : 0;
		e->mform[i] = ft_strdup(&line[4]);
		if (i == (pos.y - 1))
			break ;
	}
	e->mform[i + 1] = NULL;
}

void		recup_piece(char *line, t_obj *e)
{
	int		i;
	t_pos	pos;

	i = 6;
	pos.x = 0;
	pos.y = 0;
	while (!ft_isdigit(line[i]))
		++i;
	while (ft_isdigit(line[i]))
		pos.y = pos.y * 10 + (line[i++] - '0');
	e->pform = (char **)malloc((sizeof(char *)) * (pos.y + 2));
	e->pform[pos.y + 1] = NULL;
	while (ft_isdigit(line[++i]))
		pos.x = pos.x * 10 + (line[i] - '0');
	i = -1;
	e->p.x = pos.x;
	e->p.y = pos.y;
	while (++i < pos.y)
	{
		get_next_line(0, &line) <= 0 ? exit(0) : 0;
		e->pform[i] = ft_strdup(line);
	}
	e->pform[i] = NULL;
	len_tetri_y(e->pform, e);
	len_tetri_x(e->pform, e);
}

char		init_player(char *line, t_obj *e)
{
	char	*tp_line;
	int		i;

	i = -1;
	tp_line = ft_strdup(line);
	while (tp_line[++i])
	{
		if (tp_line[i] == 'p' && tp_line[i + 1] == '1')
		{
			e->player = 'O';
			e->advers = 'X';
			return ('1');
		}
		if (tp_line[i] == 'p' && tp_line[i + 1] == '2')
		{
			e->player = 'X';
			e->advers = 'O';
			return ('2');
		}
	}
	return (0);
}

int			get_data(char *player, t_obj *e)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (!*player && ft_strstr(line, "filler"))
			*player = init_player(line, e);
		else if (ft_strncmp(line, "Plateau", 2) == 0)
			recup_arena(line, e);
		else if (ft_strncmp(line, "Piece", 2) == 0)
		{
			recup_piece(line, e);
			return (1);
		}
	}
	return (0);
}
