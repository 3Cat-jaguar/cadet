/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:41:15 by ylee              #+#    #+#             */
/*   Updated: 2020/10/15 16:00:28 by ylee             ###   ########.fr       */
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
		ln = -n;
	else
		ln = n;
	idx = 0;
	while (ln > 0)
	{
		num[idx++] = ln % 10;
		ln = ln / 10;
	}
	if (n < 0)
		num[idx++] = '-';
	if (n == 0)
		num[idx++] = '0';
	while (idx >= 0)
		write(fd, &num[--idx], 1);
}
