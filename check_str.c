/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 19:09:47 by fignigno          #+#    #+#             */
/*   Updated: 2020/11/22 17:21:11 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print(char **str)
{
	char	*format;
	int		res;

	format = *str;
	res = 0;
	while (*format && *format != '%')
	{
		write(1, format++, 1);
		res++;
	}
	*str = format;
	return (res);
}

char	*get_description(char *str, t_params *ch, va_list args)
{
	str = check_flags(str, ch);
	str = check_width(str, ch, args);
	str = check_prec(str, ch, args);
	return (str);
}

int		find_arg(char **format, va_list args)
{
	t_params	*ch;
	int			res;

	if (!(ch = (t_params *)malloc(sizeof(t_params))))
		return (-1);
	ch->flags = 0;
	ch->precission = 0;
	ch->width = 0;
	ch->dot = 0;
	ch->zero_prec = 0;
	ch->star = 0;
	if ((res = work_with_var(format, ch, args)) < 0)
	{
		free(ch);
		return (-1);
	}
	free(ch);
	return (res);
}

int		start_work(char *format, va_list args)
{
	int		res;
	int		tmp;

	res = 0;
	while (*format)
	{
		res += print(&format);
		if ((tmp = find_arg(&format, args)) < 0)
			return (-1);
		res += tmp;
	}
	return (res);
}
