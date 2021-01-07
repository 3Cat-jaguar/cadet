/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:35:23 by ylee              #+#    #+#             */
/*   Updated: 2021/01/07 14:46:44 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

void	itobit(int size, unsigned f)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	
	for (i = size; i > 0 ; i--)
	{
		for (j = i*8-1; j >= (i-1)*8; j--)
		{
			printf("%d", (f & (1 << j)) ? 1 : 0);
		}
		printf(" ");
	}
	printf("\n");
}

int		power2(int n)
{
	int		result;

	result = 1;
	while (n > 0)
	{
		result = result * 2;
		n--;
	}
	return (result);
}

int		main(void)
{
	unsigned	f;
	unsigned	copy;
	float		realf;
	int			size;
	int			i;
	int			j;
	int			minus;
	int			exp;
	int			frac;
	int			jungsu;
	char		*result;
	int			sosu;

	realf = 123.123456789;
	f = *(unsigned *)&realf;
	copy = f;
	size = sizeof(float);
	i = 0;
	j = 0;

	printf("f : %f\n", realf);
	printf("how bit ? \n");
	itobit(size, f);
	//minus : 1  exponent : 1000010. 1  fraction :  1110110. 00111111. 00110110
	printf("size : %d\n", size);
	minus = (f >> (size * 8 - 1)) & 1;
	printf("minus ? : %d\n", minus);
	exp = (f >> (size * 8 - 9)) - (minus * 256) - 127;
	printf("exponent ? : %d\n", exp);
	frac = 0;
	jungsu = (f << 9) >> (size * 8 - exp);
	printf("jungsu ? : %d\n", jungsu);
	jungsu = jungsu + power2(exp);
	result = ft_strjoin(ft_itoa(jungsu), ".sosu");
	printf("jungsu string : %s\n", result);
	sosu = (f << (9 + exp)) >> (9 + exp);
	itobit(size, sosu);
	return(0);
}
