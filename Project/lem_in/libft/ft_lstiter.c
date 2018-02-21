/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 04:47:58 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/18 04:55:48 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*cur_lst;
	t_list	*next_lst;

	cur_lst = lst;
	while (cur_lst)
	{
		next_lst = cur_lst->next;
		f(cur_lst);
		cur_lst = next_lst;
	}
}
