/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base16.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:34:41 by ylee              #+#    #+#             */
/*   Updated: 2020/11/20 15:39:28 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_lltoa_base16(long long num)
{
	char				*result;
	char				*base;
	char				tmp[25];
	unsigned long long	ull;
	int					idx;

	base = "0123456789abcdef";
	ull = (unsigned long long)num;
	idx = 0;
	while (ull != 0)
	{
		tmp[idx++] = base[(int)(ull % 16)];
		ull = ull / 16;
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
