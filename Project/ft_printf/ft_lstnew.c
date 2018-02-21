/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 02:14:34 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/20 18:14:36 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_lst;
	size_t	c_size;

	c_size = content_size;
	if (!(new_lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new_lst->content_size = c_size;
	if (content != NULL)
	{
		new_lst->content = (void *)malloc(new_lst->content_size);
		new_lst->content = ft_memcpy(new_lst->content, content, c_size);
		new_lst->next = NULL;
	}
	else
	{
		new_lst->content_size = 0;
		new_lst->content = NULL;
		new_lst->next = NULL;
	}
	return (new_lst);
}
