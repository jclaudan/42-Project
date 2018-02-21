/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:43:47 by jclaudan          #+#    #+#             */
/*   Updated: 2017/05/15 16:43:50 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		abs(int num)
{
	return (num < 0 ? -num : num);
}

int		main(void)
{
	char		player;
	t_obj		*env;

	env = (t_obj *)malloc(sizeof(t_obj));
	player = '\0';
	while (get_data(&player, env) == 1)
	{
		play(env);
	}
	return (0);
}
