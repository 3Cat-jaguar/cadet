/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:21:31 by ylee              #+#    #+#             */
/*   Updated: 2020/11/17 14:15:16 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int				ft_printf(const char *str, ...);
void			ft_itoa_base16(unsigned int num, char **result);
void			ft_toupper_str(char **str);
void			ft_put_unsigned_int_fd(unsigned int n, int fd);
void			ft_lltoa_base16(long long num, char **result);
void			ft_uitoa(unsigned int num, char **result);

typedef struct	s_arg
{
	//flags
	int		dash;
	int		plus;
	int		space;
	int		sharp;
	int		zero;
	//width
	int		width;
	//.precision
	int		dot;
	int		precision;
	//length
	int		l;
	int		ll;
	int		h;
	int		hh;
	//specifier
	int		specifier;
}				t_arg;

char	*find_percent(va_list ap, t_arg *arg, char *str, int *idx);
t_arg	*ft_init_arg_list(t_arg *arg);
int		check_flags(t_arg *arg, char c);
int		check_specifier(char c);
int		width_or_precision(va_list ap, t_arg *arg, char *str);
int		check_length(t_arg *arg, char *str);
char	*modify_str_by_arg(va_list ap, t_arg *arg);

#endif
