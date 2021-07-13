/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   description.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:09:31 by fignigno          #+#    #+#             */
/*   Updated: 2020/11/22 17:20:57 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_flags(char *str, t_params *ch)
{
	while (1)
	{
		if (*str == '-')
			ch->flags |= MINUS_FLAG;
		else if (*str == '+')
			ch->flags |= PLUS_FLAG;
		else if (*str == ' ')
			ch->flags |= SPACE_FLAG;
		else if (*str == '#')
			ch->flags |= OCT_FLAG;
		else if (*str == '0')
			ch->flags |= ZERO_FLAG;
		else
			break ;
		++str;
	}
	return (str);
}

char	*check_width(char *str, t_params *ch, va_list args)
{
	if (ft_isdigit(*str))
	{
		ch->width = ft_atoi(str);
		while (ft_isdigit(*str))
			++str;
	}
	else if (*str == '*')
	{
		ch->width = va_arg(args, int);
		++str;
	}
	return (str);
}

char	*check_prec(char *str, t_params *ch, va_list args)
{
	if (*str != '.')
		return (str);
	else
		++str;
	ch->dot = 1;
	if (*str == '*')
	{
		ch->star = 1;
		ch->precission = va_arg(args, int);
		if (ch->precission == 0)
			ch->zero_prec = 1;
		++str;
	}
	else if (ft_isdigit(*str))
	{
		ch->precission = ft_atoi(str);
		if (ch->precission == 0)
			ch->zero_prec = 1;
		while (ft_isdigit(*str))
			++str;
	}
	ch->neg_prec = ch->precission < 0;
	return (str);
}

int		print_var(char **str, t_params *ch, va_list args)
{
	int num;

	if (**str == 'd' || **str == 'i')
		num = (print_int(ch, va_arg(args, int)));
	else if (**str == 'c')
		num = (print_char(ch, va_arg(args, int)));
	else if (**str == 's')
		num = (print_str(ch, va_arg(args, char *)));
	else if (**str == 'p')
		num = (print_pointer(ch, va_arg(args, unsigned long long)));
	else if (**str == 'x')
		num = (print_hex(ch, va_arg(args, unsigned int), 0));
	else if (**str == 'X')
		num = (print_hex(ch, va_arg(args, unsigned int), 1));
	else if (**str == 'u')
		num = (print_uns(ch, (unsigned int)va_arg(args, unsigned int)));
	else if (**str == '%')
		num = (print_percent(ch));
	else
		return (-1);
	++(*str);
	return (num);
}
