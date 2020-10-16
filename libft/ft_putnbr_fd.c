/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:41:15 by ylee              #+#    #+#             */
/*   Updated: 2020/10/16 11:39:11 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	ln;
	int			idx;
	char		num[20];

	ft_bzero(num, 20);
	if (n < 0)
		ln = (long long)n * (-1);
	else
		ln = (long long)n;
	idx = 0;
	while (ln > 0)
	{
		num[idx++] = ln % 10 + '0';
		ln = ln / 10;
	}
	if (n < 0)
		num[idx++] = '-';
	if (n == 0)
		num[idx++] = '0';
	while (idx > 0)
		write(fd, &num[--idx], 1);
}
