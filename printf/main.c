/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 09:58:23 by ylee              #+#    #+#             */
/*   Updated: 2020/10/30 13:24:04 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

void	test(char *str, ...)
{
	va_list ap;
	int		idx;

	idx = 0;
	va_start(ap, str);
	while (str[idx])
	{
		if (str[idx] != '%')
			write (1, &str[idx], 1);
		else if (str[idx] == '%')
		{
			idx++;
			if (str[idx] == 'd')
			{
				ft_putnbr_fd(va_arg(ap, int), 1);
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
}

int		main(void)
{
	test("test : %d %d %d %d %d %c %c %s %d %f %c %s %d end\n", 1, 2, 3, 4, 5, 'c', 'a', "test", -30, 2.567, '3', '\0', -1000);
	return (0);
}
