/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_unicode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:19:15 by jclaudan          #+#    #+#             */
/*   Updated: 2017/03/13 23:05:18 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		conv_to_unicode_kit(wchar_t arg, t_param *p)
{
	p->str[0] = ((arg >> 18) & 0x07) | 0xF0;
	p->str[1] = ((arg >> 12) & 0x3F) | 0x80;
	p->str[2] = ((arg >> 6) & 0x3F) | 0x80;
	p->str[3] = ((arg >> 0) & 0x3F) | 0x80;
	if ((p->l == 1 && p->conv == 's') || (p->conv == 'S'))
		p->size += 4;
}

t_param		*conv_to_unicode(wchar_t arg, t_param *p)
{
	p->str = ft_strnew(5);
	if (arg < 0x80)
	{
		p->str[0] = ((arg >> 0) & 0x7F) | 0x00;
		if ((p->l == 1 && p->conv == 's') || (p->conv == 'S'))
			p->size += 1;
	}
	else if (arg < 0x0800 && MB_CUR_MAX > 0)
	{
		p->str[0] = ((arg >> 6) & 0x1F) | 0xC0;
		p->str[1] = ((arg >> 0) & 0x3F) | 0x80;
		if ((p->l == 1 && p->conv == 's') || (p->conv == 'S'))
			p->size += 2;
	}
	else if (arg < 0x010000 && MB_CUR_MAX > 2)
	{
		p->str[0] = ((arg >> 12) & 0x0F) | 0xE0;
		p->str[1] = ((arg >> 6) & 0x3F) | 0x80;
		p->str[2] = ((arg >> 0) & 0x3F) | 0x80;
		if ((p->l == 1 && p->conv == 's') || (p->conv == 'S'))
			p->size += 3;
	}
	else if (arg < 0x110000 && MB_CUR_MAX > 3)
		conv_to_unicode_kit(arg, p);
	return (p);
}

t_param		*conv_str_unicode_kit(t_param *p, int flag)
{
	if (flag == 1)
	{
		p->str2 = ft_strdup("(null)");
	}
	if (flag == 2)
	{
		p->str2 = ft_strdup("");
	}
	if (flag == 3)
	{
		p->str2 = ft_strcat(p->str2, p->str);
		p->str2 = ft_strsub_f(p->str2, 0, p->precis);
		p->size = p->precis;
	}
	return (p);
}

t_param		*conv_str_unicode(wchar_t *arg, t_param *p)
{
	int		i;

	i = 0;
	if (arg == NULL)
		return (conv_str_unicode_kit(p, 1));
	else if (arg[0] == 0)
		return (conv_str_unicode_kit(p, 2));
	else if (arg)
	{
		while (arg[i])
		{
			p = conv_to_unicode(arg[i], p);
			if (i == 0 && p->str)
				p->str2 = ft_strdup(p->str);
			else if (p->precis != 0)
				p = conv_str_unicode_kit(p, 3);
			else
				p->str2 = ft_strcat(p->str2, p->str);
			i++;
			ft_memdel((void*)&p->str);
		}
	}
	return (p);
}
