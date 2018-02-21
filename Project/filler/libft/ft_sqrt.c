/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sblemand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:29:45 by sblemand          #+#    #+#             */
/*   Updated: 2016/11/22 02:33:56 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int	racine;
	int	sq;

	racine = 1;
	sq = 0;
	while (racine <= nb / 2)
	{
		sq = racine * racine;
		if (sq == nb)
		{
			return (racine);
		}
		racine = racine + 1;
	}
	return (0);
}
