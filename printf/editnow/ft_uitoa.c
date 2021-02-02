/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:34:41 by ylee              #+#    #+#             */
/*   Updated: 2020/11/18 17:09:41 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_uitoa(unsigned int num)
{
	char			*base;
	char			tmp[25];
	char			*result;
	int				idx;

	base = "0123456789";
	idx = 0;
	if (num == 0)
		tmp[idx++] = '0';
	while (num != 0)
	{
		tmp[idx++] = base[(int)(num % 10)];
		num = num / 10;
	}
	tmp[idx] = '\0';
	result = (char *)ft_calloc(idx, sizeof(char));
	if (!result)
		return (0);
	while (--idx >= 0)
		result[(int)num++] = tmp[idx];
	result[(int)num] = '\0';
	return (result);
}
