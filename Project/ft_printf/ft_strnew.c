/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 19:09:54 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/11 19:26:11 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*chaine;
	size_t	i;

	i = 0;
	if (!(chaine = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		chaine[i] = '\0';
		i++;
	}
	chaine[i] = '\0';
	return (chaine);
}
