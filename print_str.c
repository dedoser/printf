/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:21:21 by fignigno          #+#    #+#             */
/*   Updated: 2020/11/22 17:20:10 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wpd_str(t_params *ch, char *str)
{
	int	len;

	len = (int)ft_strlen(str);
	if (ch->width < 0)
		ch->flags |= MINUS_FLAG;
	ch->width = ((ch->width > 0) ? ch->width : -(ch->width));
	if (ch->precission <= 0 || ch->precission > len)
		ch->precission = len;
	if (ch->width > ch->precission)
		ch->width -= ch->precission;
	else
		ch->width = 0;
	ch->width = (ch->width < 0) ? 0 : ch->width;
	return (ch->width + ch->precission);
}

int		print_str(t_params *ch, char *str)
{
	int res;
	int end;
	int	len;

	if (!str)
		str = "(null)";
	if (ch->dot && ch->precission == 0)
		str = 0;
	res = wpd_str(ch, str);
	len = ft_strlen(str);
	end = (ch->precission > len) ? len : ch->precission;
	if (ch->flags & MINUS_FLAG)
	{
		write(1, str, end);
		print_line(ch->width, ' ');
	}
	else
	{
		print_line(ch->width, ' ');
		write(1, str, end);
	}
	return (res);
}
