/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:55:07 by fignigno          #+#    #+#             */
/*   Updated: 2020/11/22 17:20:10 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(t_params *ch, char c)
{
	int	res;

	if (ch->width < 0)
	{
		ch->width = -ch->width;
		ch->flags |= MINUS_FLAG;
	}
	res = (ch->width == 0) ? 1 : ch->width;
	if (ch->width != 0)
		ch->width--;
	if (ch->flags & MINUS_FLAG)
	{
		write(1, &c, 1);
		print_line(ch->width, ' ');
	}
	else
	{
		print_line(ch->width, ' ');
		write(1, &c, 1);
	}
	return (res);
}
