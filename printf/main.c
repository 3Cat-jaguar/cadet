/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 09:58:23 by ylee              #+#    #+#             */
/*   Updated: 2020/11/03 16:34:25 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libftprintf.h"

int		main(void)
{
	char		*teststr;
	long long	ptr;
	int			test1;
	char		*test2;

	teststr = "hello";
	test1 = -200;
	test2 = (char *)ft_calloc(15, sizeof(char));
	ft_itoa_base16(test1, &test2);
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
