/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:34:41 by ylee              #+#    #+#             */
/*   Updated: 2021/02/01 15:23:54 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_uitoa_base8(unsigned int num)
{
	char			*base;
	char			*result;
	char			tmp[15];
	unsigned int	uni;
	int				idx;

	base = "01234567";
	uni = (unsigned int)num;
	idx = 0;
	while (uni != 0)
	{
		tmp[idx++] = base[(uni % 8)];
		uni = uni / 8;
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
