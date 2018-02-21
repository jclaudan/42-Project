/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 03:47:27 by jclaudan          #+#    #+#             */
/*   Updated: 2017/05/25 15:35:08 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_str(char *str, char **line)
{
	char	*eol;

	eol = ft_strchr(str, '\n');
	if (eol)
	{
		eol[0] = '\0';
		*line = ft_strdup(str);
		str = ft_strncpy(str, &eol[1], ft_strlen(&eol[1]) + 1);
		return (1);
	}
	if (ft_strlen(str) > 0)
	{
		*line = ft_strdup(str);
		*str = '\0';
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;
	static char		*str = NULL;

	if (str == NULL)
		str = ft_strnew(0);
	if (fd < 0 || !str || !line || BUFF_SIZE <= 0)
		return (-1);
	while (!ft_strchr(str, '\n'))
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			return (get_str(str, line));
		buf[ret] = '\0';
		tmp = ft_strjoin(str, buf);
		free(str);
		str = tmp;
	}
	return (get_str(str, line));
}
