/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 17:20:15 by jinylee           #+#    #+#             */
/*   Updated: 2020/10/03 04:48:34 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_len(long long n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*base;
	int			len;
	long long	nb;
	int			sign;
	char		*ans;

	base = "0123456789";
	sign = (n >= 0) ? 0 : 1;
	len = (n >= 0) ? 0 : 1;
	nb = (n >= 0) ? (long long)n : (long long)n * -1;
	len += get_len(nb);
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (ans == 0)
		return (0);
	ans[len] = 0;
	while (len)
	{
		ans[--len] = base[nb % 10];
		nb /= 10;
	}
	if (sign)
		ans[0] = '-';
	return (ans);
}
