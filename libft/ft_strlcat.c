/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 11:07:51 by ylee              #+#    #+#             */
/*   Updated: 2020/10/22 17:02:12 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len > size)
		return (src_len + size);
	else if (dst_len == size)
		return (dst_len + src_len);
	while (*dst)
		dst++;
	while (dst && *src && (dst_len + 1) < size)
	{
		*dst = *src;
		dst++;
		src++;
		dst_len++;
	}
	if (dst && *dst != '\0')
		*dst = '\0';
	return (dst_len + src_len);
}
