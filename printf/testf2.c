/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:35:23 by ylee              #+#    #+#             */
/*   Updated: 2021/01/11 10:50:04 by ylee             ###   ########.fr       */
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

long long	power_n(int n, int k)
{
	long long	result;

	result = 1;
	while (k > 0)
	{
		result = result * n;
		k--;
	}
	return (result);
}

char	*ft_uitoa_base2(unsigned int num)
{
	char			*base;
	char			*result;
	char			tmp[32];
	unsigned int	uni;
	int				idx;

	base = "01";
	uni = (unsigned int)num;
	idx = 0;
	while (uni != 0)
	{
		tmp[idx++] = base[(uni % 2)];
		uni = uni / 2;
	}
	if (num == 0)
		tmp[idx++] = '0';
	tmp[idx] = '\0';
	result = (char *)ft_calloc(idx, sizeof(char));
	if (!result)
		return (0);
	while (--idx >= 0)
		result[(int)uni++] = tmp[idx];
	result[(int)uni] = '\0';
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
	long long	real_sosu;
	char		*sosu_string;
	char		*sosu_string_base2;
	int			sosu_base2_len;
	char		*sosu_string_cut;

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
	jungsu = jungsu + (int)power_n(2, exp);
	result = ft_strjoin(ft_itoa(jungsu), ".sosu");
	printf("jungsu string : %s\n", result);
	sosu = (f << (9 + exp)) >> (9 + exp);
	printf("sosu to int ? : %d\n", sosu);
	sosu_string_base2 = ft_uitoa_base2((unsigned)sosu);
	printf("sosu go string base 2 : %s\n", sosu_string_base2);
	sosu_base2_len = (int)ft_strlen(sosu_string_base2);
	printf("sosu string length : %d\n", sosu_base2_len);
	real_sosu = 0;
	while (i < sosu_base2_len)
	{
		printf("%lld\n", real_sosu);
		real_sosu = (real_sosu * 10) + ((sosu_string_base2[i] - '0') * power_n(5, i + 1));
		i++;
	}
	real_sosu = real_sosu * power_n(5, (size * 8 - 9 - exp) - sosu_base2_len);
	printf("real sosu to int ? : %lld\n", real_sosu);
	sosu_string = ft_lltoa(real_sosu);
	printf("real sosu to string : %s\n", sosu_string);
	sosu_string_cut = ft_strdup(sosu_string);
	sosu_string_cut[6] = '\0';
	real_sosu = ft_atoi(sosu_string_cut);
	if ((sosu_string[6] - '0') >= 5)
		real_sosu = real_sosu + 1;
	sosu_string = ft_itoa(real_sosu);
	result = ft_strjoin(ft_itoa(jungsu), ".");
	result = ft_strjoin(result, sosu_string);
	printf("final f string : %s\n", result);

	return(0);
}
