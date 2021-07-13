/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:44:09 by fignigno          #+#    #+#             */
/*   Updated: 2020/11/22 17:21:30 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_param
{
	int			flags;
	int			width;
	int			precission;
	int			dot;
	int			size;
	int			zero_prec;
	int			star;
	int			neg_prec;
}				t_params;

# define MINUS_FLAG	1
# define PLUS_FLAG	1 << 1
# define SPACE_FLAG	1 << 2
# define OCT_FLAG	1 << 3
# define ZERO_FLAG	1 << 4

int				ft_printf(const char *format, ...);
int				print(char **str);
char			*get_description(char *str, t_params *ch, va_list args);
int				find_arg(char **format, va_list args);
int				start_work(char *format, va_list args);
int				ft_isdigit(int c);
int				ft_atoi(const char *s);
char			*ft_itoa(int n);
size_t			ft_strlen(const char *s);
void			ft_putstr_fd(char *s, int fd);
char			*check_flags(char *str, t_params *ch);
char			*check_width(char *str, t_params *ch, va_list args);
char			*check_prec(char *str, t_params *ch, va_list args);
int				print_var(char **str, t_params *ch, va_list args);
int				work_with_var(char **str, t_params *ch, va_list args);
int				print_int(t_params *ch, int dig);
int				print_char(t_params *ch, char c);
int				print_flag(t_params *ch, int dig);
void			print_line(int len, char c);
int				wpd_int(t_params *ch, int dig, int len_num, char *w);
int				print_hex(t_params *ch, unsigned int dig, int cap);
int				wpd_hex(t_params *ch, unsigned int dig, int len_num, char *w);
int				print_pointer(t_params *ch, unsigned long long dig);
int				print_str(t_params *ch, char *str);
int				wpd_str(t_params *ch, char *str);
int				print_uns(t_params *ch, unsigned int dig);
int				print_flag_uns(t_params *ch, unsigned int dig);
int				wpd_uns(t_params *ch, unsigned int dig, int len_num, char *w);
int				print_percent(t_params *ch);
char			*ft_itoa_uns(unsigned int n);
char			*ft_itoa_base(unsigned long long nbr, int cap);
int				prpr(t_params *ch, int dig, int prec, char w);

#endif
