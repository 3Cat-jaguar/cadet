/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:20:37 by ylee              #+#    #+#             */
/*   Updated: 2020/11/07 21:54:37 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	init_list(t_arg **lst)
{
	*lst->dash = 0;
	*lst->plus = 0;
	*lst->space = 0;
	*lst->sharp = 0;
	*lst->zero = 0;

	*lst->width = 0;

	*lst->dot = 0;
	*lst->precision = 0;

	*lst->l = 0;
	*lst->ll = 0;
	*lst->h = 0;
	*lst->hh = 0;

	*lst->specifier = (char)0;
}

int		ft_printf(const char *str, ...)
{
	va_list			ap;
	char			*result;
	int				idx;
	t_arg			*tmp_arg;
}
	idx = 0;
	va_start(ap, str);
	while (str[idx])
	{
		if (str[idx] != '%')
			write (1, &str[idx], 1);
		else if (str[idx] == '%')
		{
			idx++;
			init_list(&tmp_arg);
			if (str[idx] == 'd' || str[idx] == 'i')
				ft_putnbr_fd(va_arg(ap, int), 1);
			else if (str[idx] == 'c')
				ft_putchar_fd(va_arg(ap, int), 1);
			else if (str[idx] == 's')
				ft_putstr_fd(va_arg(ap, char *), 1);
			else if (str[idx] == 'u')
				ft_put_unsigned_int_fd(va_arg(ap, unsigned int), 1);
			else if (str[idx] == 'x')
			{
				result = (char *)ft_calloc(15, sizeof(char));
				ft_itoa_base16(va_arg(ap, unsigned int), &result);
				ft_putstr_fd(result, 1);
				free(result);
				result = NULL;
			}
			else if (str[idx] == 'X')
			{
				result = (char *)ft_calloc(15, sizeof(char));
				ft_itoa_base16(va_arg(ap, unsigned int), &result);
				ft_toupper_str(&result);
				ft_putstr_fd(result, 1);
				free(result);
				result = NULL;
			}
			else if (str[idx] == 'p')
			{
				result = (char *)ft_calloc(25, sizeof(char));
				ft_lltoa_base16(va_arg(ap, long long), &result);
				ft_putstr_fd("0x", 1);
				ft_putstr_fd(result, 1);
				free(result);
				result = NULL;
			}
		}
		idx++;
	}
	va_end(ap);
	return (0);
}
