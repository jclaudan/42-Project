/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_tab_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 02:10:57 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/22 02:31:45 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_disp_tab_char(char **tab_char)
{
	size_t	i;

	i = 0;
	while (tab_char[i])
		ft_putendl(tab_char[i++]);
	return ;
}
