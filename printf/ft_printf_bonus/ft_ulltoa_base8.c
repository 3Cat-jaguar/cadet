/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base8.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:34:41 by ylee              #+#    #+#             */
/*   Updated: 2021/02/01 15:25:07 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_ulltoa_base8(unsigned long long num)
{
	char				*result;
	char				*base;
	char				tmp[25];
	unsigned long long	ull;
	int					idx;

	base = "01234567";
	ull = (unsigned long long)num;
	idx = 0;
	while (ull != 0)
	{
		tmp[idx++] = base[(int)(ull % 8)];
		ull = ull / 8;
	}
	if (num == 0)
		tmp[idx++] = '0';
	tmp[idx] = '\0';
	result = (char *)ft_calloc(idx, sizeof(char));
	if (!result)
		return (0);
	while (--idx >= 0)
		result[(int)ull++] = tmp[idx];
	result[(int)ull] = '\0';
	return (result);
}
