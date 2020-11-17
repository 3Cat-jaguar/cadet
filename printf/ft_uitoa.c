/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:34:41 by ylee              #+#    #+#             */
/*   Updated: 2020/11/17 16:42:11 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_uitoa(unsigned int num, char **result)
{
	char			*base;
	char			tmp[25];
	int				idx;

	ft_bzero(tmp, 25);
	base = "0123456789";
	idx = 0;
	if (num == 0)
		tmp[idx++] = '0';
	while (num != 0)
	{
		tmp[idx++] = base[(int)(num % 10)];
		num = num / 10;
	}
	*result = (char *)ft_calloc(idx, sizeof(char));
	while (--idx >= 0)
		(*result)[num++] = tmp[idx];
}
