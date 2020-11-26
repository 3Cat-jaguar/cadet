/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:37:06 by jinylee           #+#    #+#             */
/*   Updated: 2020/10/03 19:43:30 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char s)
{
	return (s == ' ' || (s >= 9 && s <= 13));
}

int	ft_atoi(const char *str)
{
	size_t	i;
	long	sign;
	long	ans;

	ans = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = ans * 10 + (str[i++] - '0');
		if (ans > 2147483647 && sign == 1)
			return (-1);
		if (ans > 2147483648 && sign == -1)
			return (0);
	}
	return (ans * sign);
}
