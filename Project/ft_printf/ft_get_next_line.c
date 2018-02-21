/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 03:47:27 by jclaudan          #+#    #+#             */
/*   Updated: 2017/01/05 19:23:58 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					get_next_line(const int fd, char **line)
{
	static t_utils	g;
	char			*buff;

	buff = ft_strnew(BUFF_SIZE);
	while (!ft_strchr(buff, '\n') && (g.rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		g.buff = ft_strjoin_f(g.buff, buff, 1);
		ft_strdel(&buff);
		buff = ft_strnew(BUFF_SIZE);
	}
	if (g.rd == -1 || fd < 0 || !line)
		return (-1);
	if (!ft_strlen_p(g.buff) && !ft_strlen_p(buff))
		return (0);
	if ((g.tp = ft_strchr(g.buff, '\n')))
	{
		g.ln = ft_strlen(g.tp);
		*line = ft_strsub(g.buff, 0, ft_strlen(g.buff) - g.ln);
		g.buff = ft_strsub_f(g.buff, ft_strlen(g.buff) - g.ln + 1, g.ln - 1);
		ft_strdel(&buff);
		return (1);
	}
	*line = g.buff;
	g.buff = ft_strnew(1);
	return (1);
}
