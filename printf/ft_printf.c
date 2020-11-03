/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee </var/mail/ylee>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:20:37 by ylee              #+#    #+#             */
/*   Updated: 2020/11/03 16:35:46 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		ft_printf(const char *str, ...)
{
	va_list			ap;
	int				idx;
	int				i;

	idx = 0;
	va_start(ap, str);
	while (str[idx])
	{
		if (str[idx] != '%')
			write (1, &str[idx], 1);
		else if (str[idx] == '%')
		{
			idx++;
			if (str[idx] == 'd' || str[idx] == 'i')
			{
				ft_putnbr_fd(va_arg(ap, int), 1);
			}
			else if (str[idx] == 'u')
			{
				i = va_arg(ap, int);
				if (i < 0)
					i = -i;
				ft_putnbr_fd(i, 1);
			}
			else if (str[idx] == 'c')
			{
				ft_putchar_fd(va_arg(ap, int), 1);
			}
			else if (str[idx] == 's')
			{
				ft_putstr_fd(va_arg(ap, char *), 1);
			}
			else if (str[idx] == 'f')
			{
				printf("%f", va_arg(ap, double));
			}
		}
		idx++;
	}
	va_end(ap);
	return (0);
}
