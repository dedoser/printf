/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:43:57 by fignigno          #+#    #+#             */
/*   Updated: 2020/11/22 17:20:10 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wpd_uns(t_params *ch, unsigned int dig, int len_num, char *w)
{
	int sign;

	if (ch->width < 0)
		ch->flags |= MINUS_FLAG;
	if (ch->precission < 0)
		ch->precission = len_num;
	if (ch->dot && ch->flags & ZERO_FLAG && !ch->neg_prec)
		ch->flags ^= ZERO_FLAG;
	if ((ch->flags & ZERO_FLAG) &&
			(ch->flags & MINUS_FLAG) == 0)
		*w = '0';
	else
		*w = ' ';
	if (ch->zero_prec == 1)
		ch->precission = 0;
	ch->width = ((ch->width > 0) ? ch->width : -(ch->width));
	sign = (ch->flags & PLUS_FLAG || dig < 0) ? 1 : 0;
	ch->precission = ch->precission - len_num;
	ch->precission = ch->precission * (ch->precission > 0);
	ch->width = ch->width - ch->precission - len_num - sign;
	ch->width = (ch->width > 0) * ch->width;
	return (sign + ch->precission + ch->width + len_num);
}

int		print_flag_uns(t_params *ch, unsigned int dig)
{
	int	res;

	res = 0;
	if (!(ch->flags & PLUS_FLAG) && (ch->flags & SPACE_FLAG) && dig > 0)
	{
		write(1, " ", 1);
		++res;
	}
	else if (ch->flags & PLUS_FLAG && dig > 0)
		write(1, "+", 1);
	if (dig < 0)
		write(1, "-", 1);
	return (res);
}

int		print_uns(t_params *ch, unsigned int dig)
{
	char	*num;
	int		res;
	char	w;

	if (((ch->dot && !ch->precission) || ch->zero_prec) && dig == 0)
		num = 0;
	else
		num = ft_itoa_uns(dig);
	res = wpd_uns(ch, dig, (int)ft_strlen(num), &w);
	if (ch->flags & MINUS_FLAG)
	{
		print_line(ch->precission, '0');
		ft_putstr_fd(num, 1);
		print_line(ch->width, w);
	}
	else
	{
		print_line(ch->width, w);
		print_line(ch->precission, '0');
		ft_putstr_fd(num, 1);
	}
	free(num);
	return (res);
}
