/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 04:57:31 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/20 19:10:48 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst_clean;

	if (lst != NULL)
	{
		if (!(lst_clean = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		lst_clean = f(lst);
		lst_clean->next = ft_lstmap(lst->next, f);
		return (lst_clean);
	}
	return (NULL);
}
