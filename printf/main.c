/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 09:58:23 by ylee              #+#    #+#             */
/*   Updated: 2020/11/03 10:25:02 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

void	ft_atoi_base16(int num, char **result);
void	ft_toupper_str(char **str);

void	test(char *str, ...)
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
}

int		main(void)
{
	char		*teststr;
	long long	ptr;
	int			test1;
	char		*test2;

	teststr = "hello";
	test1 = -200;
	test2 = (char *)ft_calloc(15, sizeof(char));
	ft_atoi_base16(test1, &test2);
	ptr = (long long)&teststr;
	printf("test string : %-10s end\n", teststr);
	printf("test string : 0x%llx end\n", ptr);
	printf("test string : %p end\n", &teststr);
	printf("test string : %.15d end\n", test1);
	printf("test string : %.*d end\n", 15, test1);
	printf("test hexa : %x end\n", test1);
	printf("test hexa : %s end\n", test2);
	ft_toupper_str(&test2);
	printf("test hexa : %s end\n", test2);
	free(test2);
/*
	teststr = "test string";
	test("test : %d %i %d %d %u %c %c %s %d %f %c %s %u end\n", 1, 2, 3, 4, 5, 'c', 'a', "test", -30, 2.567, '3', "\0", -1000);
	printf("test : %d %i %d %d %u %c %c %s %d %f %c %s %u end\n", 1, 2, 3, 4, 5, 'c', 'a', "test", -30, 2.567, '3', "\0", -1000);
	printf("%s\n", teststr);
	printf("%x\n", &teststr);
	printf("%d\n", &teststr);

*/
	return (0);
}
