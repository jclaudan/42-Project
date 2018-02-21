/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:57:23 by jclaudan          #+#    #+#             */
/*   Updated: 2017/01/05 18:11:59 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <fcntl.h>

# define BUFF_SIZE 4

typedef struct		s_utils
{
	char			*buff;
	char			*tp;
	int				rd;
	int				ln;
}					t_utils;

int					get_next_line(const int fd, char **line);

#endif
