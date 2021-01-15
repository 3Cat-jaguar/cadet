/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:35:23 by ylee              #+#    #+#             */
/*   Updated: 2021/01/15 16:59:31 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

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

char	*testf(float num)
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
	char		*tmp;

	realf = num;
	f = *(unsigned *)&realf;
	copy = f;
	size = sizeof(float);
	i = 0;
	j = 0;
	tmp = NULL;
	printf("f num : %f\n", realf);
	itobit(size, f);
	minus = (f >> (size * 8 - 1)) & 1;
	printf("minus? : %d\n", minus);
	exp = (f >> (size * 8 - 9)) - (minus * 256) - 127;
	printf("exp? : %d\n", exp);
	frac = 0;
	if (exp == 0)
		jungsu = 1;
	else if (exp < 0)
		jungsu = 0;
	else
	{
		jungsu = (f << 9) >> (size * 8 - exp);
		printf("jungsu bit : %d\n", jungsu);
		jungsu = jungsu + (int)power_n(2, exp);
		printf("jungsu : %d\n", jungsu);
	}
	if (exp <= 0)
		sosu = (((f << 9) >> 9) + (int)power_n(2, size * 8 - 9)) >> exp;
	else
		sosu = (f << (9 + exp)) >> (9 + exp);
	printf("sosu : %d\n", sosu);
	sosu_string_base2 = ft_uitoa_base2((unsigned)sosu);
	printf("sosu_base2 : %s\n", sosu_string_base2);
	sosu_base2_len = (int)ft_strlen(sosu_string_base2);
	real_sosu = 0;
	while (ft_atoi(&sosu_string_base2[i]) != 0 && i < sosu_base2_len)
	{
		if ((real_sosu * 10) + ((sosu_string_base2[i] - '0') * power_n(5, i + 1)) > 0)
			real_sosu = (real_sosu * 10) + ((sosu_string_base2[i] - '0') * power_n(5, i + 1));
		printf("real_sosu : %lld\n", real_sosu);
		i++;
	}
	free(sosu_string_base2);
	sosu_string_base2 = NULL;
	real_sosu = real_sosu * power_n(5, (size * 8 - 9 - exp) - sosu_base2_len);
	printf("real_sosu : %lld\n", real_sosu);
	sosu_string = ft_lltoa(real_sosu);
	sosu_string_cut = ft_strdup(sosu_string);
	sosu_string_cut[6] = '\0';
	real_sosu = ft_atoi(sosu_string_cut);
	printf("sosu : %lld\n", real_sosu);
	if ((sosu_string[6] - '0') >= 5)
		real_sosu = real_sosu + 1;
	free(sosu_string);
	sosu_string = ft_lltoa(real_sosu);
	printf("sosu_string : %s\n", sosu_string);
	result = ft_itoa(jungsu);
	tmp = ft_strjoin(result, ".");
	free(result);
	result = ft_strjoin(tmp, sosu_string);
	free(sosu_string);
	sosu_string = NULL;
	free(tmp);
	tmp = NULL;
	if (minus != 0)
	{
		tmp = ft_strjoin("-", result);
		free(result);
		result = tmp;
	}
	free(sosu_string_cut);
	return(result);
}
