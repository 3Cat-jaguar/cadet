/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:57:11 by jinylee           #+#    #+#             */
/*   Updated: 2020/10/03 13:16:54 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *dst, int c, size_t t)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)dst;
	while (i < t)
	{
		if (s[i] == (unsigned char)c)
			return (s + i);
		i++;
	}
	return (0);
}
