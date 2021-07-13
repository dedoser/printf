/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:01:25 by fignigno          #+#    #+#             */
/*   Updated: 2020/11/22 17:20:10 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count(unsigned long long n)
{
	int res;

	res = 0;
	if (n < 0)
	{
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		++res;
	}
	return (res);
}

char		*ft_itoa_base(unsigned long long nbr, int cap)
{
	char		*base;
	int			size;
	long long	tmp;
	char		*res;

	base = (!cap) ? "0123456789abcdef" : "0123456789ABCDEF";
	tmp = nbr;
	size = count(tmp);
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (tmp == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	res[size] = '\0';
	while (tmp != 0)
	{
		res[--size] = base[tmp % 16];
		tmp /= 16;
	}
	return (res);
}

int			wpd_hex(t_params *ch, unsigned int dig, int len_num, char *w)
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

int			print_hex(t_params *ch, unsigned int dig, int cap)
{
	char	*num;
	int		res;
	char	w;

	if (((ch->dot && !ch->precission) || ch->zero_prec) && dig == 0)
		num = 0;
	else
		num = ft_itoa_base(dig, cap);
	res = wpd_hex(ch, dig, (int)ft_strlen(num), &w);
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
