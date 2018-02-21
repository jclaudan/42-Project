/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:20:57 by jclaudan          #+#    #+#             */
/*   Updated: 2017/03/13 23:40:27 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			what_conv(t_param *p)
{
	int	flag;

	if_is_other(p);
	p = add_pourcent(p, p->frm, p->i);
	if_is_d(p);
	if_is_x(p);
	if_is_u(p);
	if_is_o(p);
	if_is_p(p);
	flag = if_is_c(p);
	if_is_s(p);
	if (p->conv == 'S')
		p->big_s = 1;
	if (flag == -1)
		p->flag = 1;
	p->wildcard_p = 0;
	p->wildcard_f = 0;
}

static int			printf_return(t_param *p)
{
	if (p->flag == 1)
	{
		return (-1);
	}
	else
	{
		return (p->size);
	}
}

void				ft_print(const char *format, va_list *ap, t_param *p)
{
	if (p->conv == '%' || not_in_list(p->conv) == 1)
		what_conv(p = recup_format(format + p->i, p, NULL));
	else
	{
		if (if_wildcard(format + p->i, p, va_arg(*ap, void *)) == 1)
		{
			if (p->wildcard_p == 1 && p->wildcard_f == 1)
				if_wildcard_p(p, va_arg(*ap, void *));
			what_conv(p = recup_format(format + p->i, p, va_arg(*ap, void *)));
		}
		else
			what_conv(p = recup_format(format + p->i, p, p->arg));
	}
}

int					ft_printf(const char *format, ...)
{
	t_param	*p;
	va_list	ap;

	if (!(p = (t_param *)malloc(sizeof(t_param))))
		return (-1);
	init_a_null(p, format);
	va_start(ap, format);
	while (format[p->i])
	{
		if (format[p->i] == '%' && is_conv_in(p->frm + p->i + 1, p) == 1)
		{
			ft_print(format, &ap, p);
			p->i += (ft_strlen_p(p->str_p) + 1);
			if (!(format[p->i] != '%' && format[p->i] != '\0'))
				continue ;
			print_one_char(p, format[p->i], 2);
		}
		else if (format[p->i + 1] == '\0' && format[p->i] == '%')
			print_one_char(p, format[p->i], 1);
		else
			print_one_char(p, format[p->i], 2);
		p->i++;
	}
	va_end(ap);
	return (printf_return(p));
}
