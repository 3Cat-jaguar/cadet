/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base16.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:34:41 by ylee              #+#    #+#             */
/*   Updated: 2020/11/02 15:06:15 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_atoi_base16(int num, char **result)
{
	char			*base;
	char			tmp[15];
	unsigned int	uni;
	int				idx;

	base = "0123456789abcdef";
	uni = (unsigned int)num;
	idx = 0;
	while (uni > 0)
	{
		tmp[idx++] = base[(uni % 16)];
		uni = uni / 16;
	}
	while (--idx >= 0)
		(*result)[uni++] = tmp[idx];
}
