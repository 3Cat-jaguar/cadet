/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:32:09 by ylee              #+#    #+#             */
/*   Updated: 2021/01/13 11:22:54 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_lltoa(long long int n)
{
	unsigned long long	num;
	char				str[25];
	int					idx;
	char				*result;

	idx = 0;
	if (n < 0)
		num = (unsigned long long)-n;
	else
		num = (unsigned long long)n;
	while (num > 0)
	{
		str[idx++] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		str[idx++] = '-';
	else if (n == 0)
		str[idx++] = '0';
	str[idx] = '\0';
	if (!(result = (char *)ft_calloc(ft_strlen(str) + 1, sizeof(char))))
		return (0);
	while (--idx >= 0)
		result[ft_strlen(str) - 1 - idx] = str[idx];
	return (result);
}
