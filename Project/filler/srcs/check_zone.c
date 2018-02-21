/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:43:59 by jclaudan          #+#    #+#             */
/*   Updated: 2017/05/15 16:48:36 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		len_tetri_x(char **tetri, t_obj *e)
{
	int		j;
	int		i;
	int		imin;
	int		imax;
	int		diez;

	imin = 0;
	imax = 0;
	diez = 0;
	j = -1;
	while (tetri[++j])
	{
		i = -1;
		while (tetri[j][++i])
			if (tetri[j][i] == '*')
			{
				if (++diez == 1)
					imin = i;
				i < imin ? imin = i : 0;
				i > imax ? imax = i : 0;
			}
	}
	e->len_form_x = (imax - imin + 1);
	return ;
}

int			len_tetri_y(char **tetri, t_obj *e)
{
	int		y;
	int		x;
	int		count;

	y = 0;
	count = 0;
	while (tetri[y])
	{
		x = 0;
		while (tetri[y][x])
		{
			if (tetri[y][x] == '*')
			{
				count++;
				e->len_form_y = count;
				break ;
			}
			x++;
		}
		y++;
	}
	return (y);
}

int			iswall(t_obj *e, t_pos p, t_pos c)
{
	int		y;
	int		x;

	y = p.y + c.y;
	x = p.x + c.x;
	if (e->mform[y][x] != '.' && e->mform[y][x] != 'O' && e->mform[y][x] != 'X')
		return (1);
	return (0);
}

int			is_inmap(t_pos m, t_pos pp, t_pos c)
{
	pp.y = pp.y + c.y;
	pp.x = pp.x + c.x;
	if ((pp.x >= 0 && pp.x < m.x) && (pp.y >= 0 && pp.y < m.y))
		return (1);
	return (0);
}

int			can_place(t_obj *e, t_pos c)
{
	t_pos	pp;

	e->np = 0;
	pp.y = -1;
	while (++pp.y < e->p.y)
	{
		pp.x = -1;
		while (++pp.x < e->p.x)
		{
			if (e->pform[pp.y][pp.x] == '*')
			{
				if (is_inmap(e->m, pp, c) && !iswall(e, pp, c) &&
						e->mform[pp.y + c.y][pp.x + c.x] != e->advers)
				{
					if (e->mform[pp.y + c.y][pp.x + c.x] == e->player)
						++e->np;
				}
				else
					return (0);
			}
		}
	}
	return ((e->np == 1) ? 1 : 0);
}
