/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:29:13 by jclaudan          #+#    #+#             */
/*   Updated: 2017/01/05 19:27:25 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_f(char *s1, char *s2, int flag)
{
	char	*new_string;

	new_string = ft_strjoin_p(s1, s2);
	flag == 1 ? ft_strdel(&s1) : 0;
	flag == 2 ? ft_strdel(&s2) : 0;
	if (flag == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (new_string);
}
