/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:36:34 by fignigno          #+#    #+#             */
/*   Updated: 2020/11/22 17:20:10 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wpd_per(t_params *ch, char *w)
{
	if (ch->width < 0)
		ch->flags |= MINUS_FLAG;
	if (ch->flags & ZERO_FLAG && (ch->flags & MINUS_FLAG) == 0)
		*w = '0';
	else
		*w = ' ';
	if (ch->width)
		ch->width--;
	return (ch->width + 1);
}

int		print_percent(t_params *ch)
{
	int		res;
	char	w;

	res = wpd_per(ch, &w);
	if (ch->flags & MINUS_FLAG)
	{
		write(1, "%%", 1);
		print_line(ch->width, w);
	}
	else
	{
		print_line(ch->width, w);
		write(1, "%%", 1);
	}
	return (res);
}
