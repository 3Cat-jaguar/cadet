/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:35:23 by ylee              #+#    #+#             */
/*   Updated: 2021/01/04 15:22:24 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

	realf = 123.123456789;
	f = *(unsigned *)&realf;
	copy = f;
	size = sizeof(float);
	i = 0;
	j = 0;

	printf("f : %f\n", realf);
	printf("how bit ? \n");
	for (i = size; i > 0 ; i--)
	{
		for (j = i*8-1; j >= (i-1)*8; j--)
		{
			printf("%d", (f & (1 << j)) ? 1 : 0);
		}
		printf(" ");
	}
	//minus : 1  exponent : 1000010. 1  fraction :  1110110. 00111111. 00110110
	printf("\n");
	printf("size : %d\n", size);
	minus = (f >> (size * 8 - 1)) & 1;
	printf("minus ? : %d\n", minus);
	exp = (f >> (size * 8 - 9)) - (minus * 256) - 127;
	printf("exponent ? : %d\n", exp);
	frac = 0;
	jungsu = (f >> (size * 8 - 9 - exp);
	return(0);
}
