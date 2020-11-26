/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:47:57 by jinylee           #+#    #+#             */
/*   Updated: 2020/10/02 21:12:43 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp_src;
	int				flag;

	temp_src = (unsigned char*)src;
	i = 0;
	flag = 1;
	while (i < n && temp_src[i] && flag)
	{
		if (temp_src[i] == (unsigned char)c)
			flag = 0;
		i++;
	}
	if (flag == 0)
	{
		ft_memcpy(dst, temp_src, i);
		return (dst + i);
	}
	else
	{
		ft_memcpy(dst, temp_src, n);
		return (0);
	}
}
