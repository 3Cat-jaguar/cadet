/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base16.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:34:41 by ylee              #+#    #+#             */
/*   Updated: 2020/11/24 16:57:50 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoa_base16(unsigned int num)
{
	char			*base;
	char			*result;
	char			tmp[15];
	unsigned int	uni;
	int				idx;

	base = "0123456789abcdef";
	uni = (unsigned int)num;
	idx = 0;
	while (uni != 0)
	{
		tmp[idx++] = base[(uni % 16)];
		uni = uni / 16;
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
