/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:27:31 by jclaudan          #+#    #+#             */
/*   Updated: 2017/01/05 18:22:35 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_p(char const *s1, char const *s2)
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
	return (new_string);
}
