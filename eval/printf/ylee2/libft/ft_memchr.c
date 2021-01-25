/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 18:14:59 by ylee              #+#    #+#             */
/*   Updated: 2020/10/12 13:45:26 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	unsigned char		uc;
	const unsigned char	*s;

	i = 0;
	uc = (unsigned char)c;
	s = str;
	while (i < n)
	{
		if (s[i] == uc)
			return ((void *)&s[i]);
		i++;
	}
	return (0);
}
