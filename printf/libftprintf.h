/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:21:31 by ylee              #+#    #+#             */
/*   Updated: 2020/11/17 13:28:14 by ylee             ###   ########.fr       */
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

t_arg	*ft_init_arg_list(void);

#endif
