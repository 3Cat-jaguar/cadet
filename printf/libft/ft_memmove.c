/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:47:23 by ylee              #+#    #+#             */
/*   Updated: 2020/10/12 14:48:03 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int			i;
	char		*d;
	const char	*s;

	if (!dst && !src)
		return (0);
	d = dst;
	s = src;
	if (dst < src)
	{
		i = 0;
		while (i < (int)len)
		{
			*(d + i) = *(s + i);
			i++;
		}
	}
	else if (d > s)
	{
		i = (int)len;
		while (--i >= 0)
			*(d + i) = *(s + i);
	}
	return (dst);
}
