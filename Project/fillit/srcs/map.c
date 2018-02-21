/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slitim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 22:05:20 by slitim            #+#    #+#             */
/*   Updated: 2016/12/20 22:05:25 by slitim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			sqrt_tetri(int nb)
{
	int	racine;

	racine = 2;
	while (racine * racine < nb)
		racine++;
	return (racine);
}

void		free_map(t_map *map)
{
	ft_free_all((void **)map->matrice);
	ft_memdel((void **)&map);
}

t_map		*new_map(int len_cote)
{
	t_map	*map;
	int		i;
	int		j;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (!(map->matrice = (char **)malloc(sizeof(char *) * len_cote)))
		return (NULL);
	map->size = len_cote;
	j = 0;
	while (j < len_cote)
	{
		map->matrice[j] = ft_strnew(len_cote);
		i = 0;
		while (i < len_cote)
		{
			map->matrice[j][i] = '.';
			i++;
		}
		j++;
	}
	return (map);
}

int			check_l_column(char **tetri)
{
	int						count[2];
	int						yx[2];

	yx[0] = 0;
	yx[1] = 0;
	count[1] = 0;
	while (tetri[yx[0]][yx[1]] && tetri[yx[0]][yx[1]] != '#' && tetri)
	{
		count[0] = 0;
		while (tetri[yx[0]])
		{
			if (tetri[yx[0]][yx[1]] == '.')
				count[0]++;
			yx[0]++;
		}
		if (count[0] == yx[0])
		{
			yx[0] = 0;
			count[1]++;
		}
		else
			break ;
		yx[1]++;
	}
	return (count[1]);
}

char		**cut_column(char **tetri)
{
	int						y;
	char					**tmp;
	size_t					len;
	int						start;

	tmp = NULL;
	y = 0;
	if (check_l_column(tetri) == 0)
		return (tetri);
	if ((start = check_l_column(tetri)) != 0)
	{
		if (!(tmp = (char **)malloc(sizeof(char *) * 5)))
			return (NULL);
		while (tetri[y])
		{
			len = ft_strlen(tetri[y]);
			tmp[y] = ft_strsub(tetri[y], start, len);
			y++;
		}
		tmp[y] = NULL;
	}
	ft_free_all((void **)tetri);
	return (tmp);
}
