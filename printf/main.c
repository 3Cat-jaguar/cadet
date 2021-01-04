/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 09:58:23 by ylee              #+#    #+#             */
/*   Updated: 2020/12/18 16:34:44 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libftprintf.h"

int		main(void)
{
	char		testc;
	char		*teststr;
//	long long	ptr;
	int			test1;
//	char		*test2;
	unsigned int	usi;
	float		testfloat;
	long long int ull;
	short int	si;

	testc = 'a';
	teststr = "hello";
	testfloat = 123;
//	ptr = &teststr;
	test1 = -123456789;
	ull = 9223372036854775807;
	usi = 429876405;
	si = (short int)test1;

	printf("%d\n", printf("%s|%n|\n", "%n : ", &test1));
	printf("%d\n", test1);
	ft_printf("test %2.*k\n", 3);
	printf("test %2.*k\n", 3);
	
/*
	printf("%%hd : |%hd|\n", si);
	printf("%%d : |%d|\n", (int)si);
	printf("%%d : |%d|\n", test1);
	printf("%%hhd : |%hhd|\n", ull);
	printf("%%hd : |%hd|\n", ull);
	printf("%%d : |%d|\n",  ull);
	printf("%%ld : |%ld|\n",  ull);
	printf("%%lld : |%lld|\n",  ull);

*/
//	printf("%%i : |%i| , %%hi : |%hi|, %%hhi : |%hhi| \n", 1000000, (short)1000000, (char)1000000);
//	ft_printf("%%i : |%i| , %%hi : |%hi|, %%hhi : |%hhi| \n", 1000000, (short)1000000, (char)1000000);


/*
	printf("|%-4.c|\n", 'y');
	ft_printf("|%-4.c|\n", 'y');

	printf("nullc %c nulls %s nulld %d\n", 0, NULL, 0);
	ft_printf("%%\n");
	ft_printf("%.5i\n", 2);
	ft_printf("%05%\n");
	printf("test %% : %20%\n");
	ft_printf("test %% : %20%\n");
	printf("test +d : %+d\n", test1);
	ft_printf("tess +d : %+#- 023.*lld\n", 13, test1);
	printf("test i : %i\n", test1);
	ft_printf("tess i : %i\n", test1);
	printf("test c : %c\n", testc);
	ft_printf("tess c : %c\n", testc);
	printf("test s : %s\n", teststr);
	ft_printf("tess s : %s\n", teststr);
	printf("test p : %p\n", &teststr);
	ft_printf("tess p : %p\n", &teststr);
	printf("test u : %u\n", usi);
	ft_printf("tess u : %u\n", usi);
	printf("test x : %x\n", usi);
	ft_printf("tess x : %x\n", usi);
	printf("test X : %X\n", usi);
	ft_printf("tess X : %X\n", usi);
	printf("test : d = %d, i = %i, c = %c, s = %s, p = %p, u = %u, x = %x, X = %X end\n", test1, test1, testc, teststr, &teststr, usi, usi, usi);
	ft_printf("tess : d = %*.*d, i = %i, c = %c, s = %*.*s, p = %*p, u = %u, x = %x, X = %X end\n", 1, 2, test1, test1, testc, 3, 4, teststr, 5, &teststr, usi, usi, usi);
	printf("test i : %i\n", test1);
	ft_printf("tess i : %i\n", test1);
	printf("test c : %c\n", testc);
	ft_printf("tess c : %c\n", testc);

*/

/*	
	printf("test flag + : % d\n", test1);
	printf("test flag +0 : %+010d\n", test1);
	printf("test flag 0+ : %0+10d\n", test1);
	printf("test flag  0 : % 010d\n", test1);
	printf("test flag 0  : %0 10d\n", test1);
	printf("test flag #10o : %0#10o\n", test1);
	printf("test flag #15e : %0#15e\n", 123.45678);
	printf("test flag #15f : %0#15f\n", 123.45678);
	printf("test flag #15a : %0#15a\n", 123.45678);
	printf("test flag #15g : %0#15g\n", 123.45678);
	printf("test flag f : %f\n", 123.45678);
	printf("test flag #f : %#f\n", 123.45678);
	printf("test flag 0#f : %0#f\n", 123.45678);
	printf("test flag 10f : %10f\n", 123.45678);
	printf("test flag #10f : %#10f\n", 123.45678);
	printf("test flag 15f : %15f\n", testfloat);
	printf("test flag #15f : %#15f\n", testfloat);
	printf("test flag f : %f\n", testfloat);
	printf("test flag #f : %#f\n", testfloat);


	teststr = "hello";
	test1 = -200;
	test2 = (char *)ft_calloc(15, sizeof(char));
	ft_itoa_base16(test1, &test2);
	ptr = (long long)&teststr;
	printf("test string : %10s end\n", teststr);
	printf("test string : %-10s end\n", teststr);
	printf("test string : %3s end\n", teststr);
	printf("test string : %-3s end\n", teststr);
	printf("test string : 0x%llx end\n", ptr);
	printf("test string : %p end\n", &teststr);
	printf("test string : %.15d end\n", test1);
	printf("test string : %.*d end\n", 15, test1);
	printf("test flag - : %10d end\n", test1);
	printf("test flag - : %-10d end\n", test1);
	printf("test flag - : %2d end\n", test1);
	printf("test flag - : %-2d end\n", test1);
	printf("test flag 0 : %010d end\n", test1);
	printf("test flag 0 : %10d end\n", test1);
	printf("test flag 0 : %f, %010f end\n", -0.23, -0.23);
	printf("test flag 0 : %f, %010f end\n", -12.23, -12.23);
	printf("test flag 0 : %f, %010f end\n", -123.23, -123.23);
	printf("test flag 0 : %f, %010f end\n", -1234.23, -1234.23);
	printf("test flag 0 : %f, %010f end\n", 1234.23, 1234.23);
	printf("test flag 0 : %f, %010f end\n", -0.123423, -0.123423);
	printf("test flag 0 : %f, %015f end\n", -0.123423, -0.123423);
	printf("test flag 0 : %f, %010f end\n", 0.123456789, 0.123456789);
	printf("test flag 0 : %f, %010f end\n", -12345678.9, -12345678.9);
	printf("test flag 0 : %f, %015f end\n", -12345678.9, -12345678.9);
	printf("test flag 0 : %f, %015f end\n", -12345678.9, -12345678.9);
	printf("test flag .* : %d, %.10d end\n", 123, 123);
	printf("test hexa : %x end\n", test1);
	printf("test hexa : %s end\n", test2);
	ft_toupper_str(&test2);
	printf("test hexa : %s end\n", test2);
	usi = 4294967295;
	printf("%u\n", usi);
	ft_put_unsigned_int_fd(4294967295, 1);
	printf("\n");
	printf("%u\n",0);
	ft_put_unsigned_int_fd(0, 1);
	printf("\n");
	printf("%u\n", -1);
	ft_put_unsigned_int_fd(-1, 1);
	free(test2);

	teststr = "test string";
	test("test : %d %i %d %d %u %c %c %s %d %f %c %s %u end\n", 1, 2, 3, 4, 5, 'c', 'a', "test", -30, 2.567, '3', "\0", -1000);
	printf("test : %d %i %d %d %u %c %c %s %d %f %c %s %u end\n", 1, 2, 3, 4, 5, 'c', 'a', "test", -30, 2.567, '3', "\0", -1000);
	printf("%s\n", teststr);
	printf("%x\n", &teststr);
	printf("%d\n", &teststr);

*/

//	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}
