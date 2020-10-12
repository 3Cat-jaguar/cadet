/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 18:01:35 by ylee              #+#    #+#             */
/*   Updated: 2020/10/12 13:45:04 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		uc;

	i = 0;
	d = dst;
	s = src;
	uc = (unsigned char)c;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == uc)
			return ((void *)&d[i + 1]);
		i++;
	}
	return (0);
}
