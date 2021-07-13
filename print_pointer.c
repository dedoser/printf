/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:39:13 by fignigno          #+#    #+#             */
/*   Updated: 2020/11/22 17:20:10 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_pointer(t_params *ch, unsigned long long dig)
{
	char	*num;
	int		res;
	char	w;

	if (!ch->precission && ch->dot)
		num = 0;
	else
		num = ft_itoa_base(dig, 0);
	res = wpd_hex(ch, dig, (int)ft_strlen(num) + 2, &w);
	if (ch->flags & MINUS_FLAG)
	{
		write(1, "0x", 2);
		ft_putstr_fd(num, 1);
		print_line(ch->width, w);
	}
	else
	{
		print_line(ch->width, w);
		write(1, "0x", 2);
		ft_putstr_fd(num, 1);
	}
	free(num);
	return (res);
}
