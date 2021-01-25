/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_int_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:41:15 by ylee              #+#    #+#             */
/*   Updated: 2020/11/04 14:07:52 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_put_unsigned_int_fd(unsigned int n, int fd)
{
	int			idx;
	char		num[20];

	ft_bzero(num, 20);
	idx = 0;
	if (n == 0)
		num[idx++] = '0';
	while (n != 0)
	{
		num[idx++] = n % 10 + '0';
		n = n / 10;
	}
	while (idx > 0)
		write(fd, &num[--idx], 1);
}
