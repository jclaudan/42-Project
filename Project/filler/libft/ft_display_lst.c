/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 23:08:40 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/22 02:09:48 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_display_lst(t_list *dis_lst)
{
	t_list	*next_lst;
	t_list	*dis_lst_tp;

	dis_lst_tp = dis_lst;
	next_lst = NULL;
	while (dis_lst_tp)
	{
		next_lst = dis_lst_tp->next;
		ft_putstr((const char *)dis_lst_tp->content);
		dis_lst_tp = next_lst;
	}
	return ;
}
