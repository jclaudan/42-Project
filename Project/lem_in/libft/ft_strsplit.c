/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:55:45 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/20 20:59:23 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(char const *s, char c)
{
	size_t		i;
	size_t		nb_word;

	i = 0;
	nb_word = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			nb_word++;
			while (s[i] != c && s[i])
				i++;
			--i;
		}
		i++;
	}
	return (nb_word);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	char		**tb;
	size_t		start;
	size_t		n;

	i = 0;
	n = 0;
	if (!(tb = (char **)malloc(sizeof(char *) * ft_count_word(s, c) + 1)) || !s)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			if (!(tb[n++] = ft_strsub(s, start, (i - start))))
				return (NULL);
			--i;
		}
		i++;
	}
	tb[n] = 0;
	return (tb);
}
