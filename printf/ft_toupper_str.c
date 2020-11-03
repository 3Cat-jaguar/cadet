/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 09:59:00 by ylee              #+#    #+#             */
/*   Updated: 2020/11/03 16:31:57 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_toupper_str(char **str)
{
	int		idx;
	char	*tmp;

	idx = 0;
	tmp = *str;
	while (tmp[idx])
	{
		tmp[idx] = ft_toupper(tmp[idx]);
		idx++;
	}
	*str = tmp;
}
