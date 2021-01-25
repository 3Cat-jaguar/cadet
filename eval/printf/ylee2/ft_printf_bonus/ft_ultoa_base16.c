/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base16.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:34:41 by ylee              #+#    #+#             */
/*   Updated: 2020/12/08 14:47:08 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_ultoa_base16(unsigned long num)
{
	char				*result;
	char				*base;
	char				tmp[25];
	unsigned long		ul;
	int					idx;

	base = "0123456789abcdef";
	ul = (unsigned long)num;
	idx = 0;
	while (ul != 0)
	{
		tmp[idx++] = base[(int)(ul % 16)];
		ul = ul / 16;
	}
	if (num == 0)
		tmp[idx++] = '0';
	tmp[idx] = '\0';
	result = (char *)ft_calloc(idx, sizeof(char));
	if (!result)
		return (0);
	while (--idx >= 0)
		result[(int)ul++] = tmp[idx];
	result[(int)ul] = '\0';
	return (result);
}
