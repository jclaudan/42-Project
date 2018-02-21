/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 03:39:29 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/18 04:20:01 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cur_lst;
	t_list	*next_lst;

	cur_lst = *alst;
	while (cur_lst)
	{
		next_lst = cur_lst->next;
		del(cur_lst->content, cur_lst->content_size);
		free(cur_lst);
		cur_lst = next_lst;
	}
	*alst = NULL;
}
