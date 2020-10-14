/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:32:09 by ylee              #+#    #+#             */
/*   Updated: 2020/10/14 15:57:32 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long long	num;
	char		str[20];
	int			idx;
	char		*result;

	idx = 0;
	num = (long long)n;
	if (num < 0)
		num = -num;
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
