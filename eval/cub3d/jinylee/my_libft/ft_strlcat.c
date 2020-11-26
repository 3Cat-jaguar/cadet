/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 00:36:31 by jinylee           #+#    #+#             */
/*   Updated: 2020/10/02 12:04:01 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	ans;

	i = 0;
	dst_len = ft_strlen(dst);
	ans = ft_strlen(src);
	j = dst_len;
	while (i + dst_len + 1 < size && src[i])
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	if (dst_len > size)
		return (size + ans);
	return (ans + dst_len);
}
