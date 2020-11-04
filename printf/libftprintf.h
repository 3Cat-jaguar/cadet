/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee </var/mail/ylee>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:21:31 by ylee              #+#    #+#             */
/*   Updated: 2020/11/04 15:42:43 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int 	ft_printf(const char *str, ...);
void	ft_itoa_base16(unsigned int num, char **result);
void	ft_toupper_str(char **str);
void	ft_put_unsigned_int_fd(unsigned int n, int fd);
void	ft_lltoa_base16(long long num, char **result);
void	ft_uitoa(unsigned int num, char **result);

#endif
