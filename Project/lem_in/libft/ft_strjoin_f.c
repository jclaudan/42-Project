/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:29:13 by jclaudan          #+#    #+#             */
/*   Updated: 2017/03/13 15:35:39 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		free_flag(int flag, char *s1, char *s2)
{
	if (s1)
		flag == 1 ? ft_strdel(&s1) : 0;
	if (s2)
		flag == 2 ? ft_strdel(&s2) : 0;
	if (flag == 3)
	{
		if (s2)
			ft_strdel(&s1);
		if (s2)
			ft_strdel(&s2);
	}
	return ;
}

char			*ft_strjoin_f(char *s1, char *s2, int flag)
{
	char	*new_string;
	size_t	l_s1;
	size_t	l_s2;
	size_t	i;
	size_t	j;

	i = -1;
	l_s1 = ft_strlen_p((char *)s1);
	l_s2 = ft_strlen_p((char *)s2);
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (!(new_string = (char *)malloc(sizeof(char) * (l_s1 + l_s2 + 1))))
		return (NULL);
	while (s1[++i] != '\0')
		new_string[i] = (char)s1[i];
	j = -1;
	while (s2[++j] != '\0')
		new_string[i + j] = s2[j];
	new_string[i + j] = '\0';
	free_flag(flag, s1, s2);
	return (new_string);
}
