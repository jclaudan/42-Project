/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:16:45 by jclaudan          #+#    #+#             */
/*   Updated: 2016/11/09 20:22:02 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncat(char *dest, const char *src, size_t n)
{
	char		*dt;

	dt = dest;
	while (*dt != '\0')
		dt++;
	while (n > 0 && *src != '\0')
	{
		*dt = *src;
		dt++;
		src++;
		n--;
	}
	*dt = '\0';
	return (dest);
}
