/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 15:02:55 by jinylee           #+#    #+#             */
/*   Updated: 2020/10/03 19:09:51 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dst;

	if (src == dst || n == 0)
		return (dst);
	if (dst < src)
	{
		temp_src = (unsigned char *)src;
		temp_dst = (unsigned char *)dst;
		while (n--)
			*temp_dst++ = *temp_src++;
	}
	else
	{
		temp_dst = (unsigned char *)dst + (n - 1);
		temp_src = (unsigned char *)src + (n - 1);
		while (n--)
			*temp_dst-- = *temp_src--;
	}
	return (dst);
}
