/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 09:59:00 by ylee              #+#    #+#             */
/*   Updated: 2020/11/18 16:14:43 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_toupper_str(char *str)
{
	int		idx;

	idx = 0;
	while (str[idx])
	{
		str[idx] = ft_toupper(str[idx]);
		idx++;
	}
	return (str);
}
