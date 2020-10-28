/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 11:07:51 by ylee              #+#    #+#             */
/*   Updated: 2020/10/22 23:25:52 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len > size)
		return (src_len + size);
	while (*dst)
		dst++;
	i = dst_len;
	while (dst && *src && (i + 1) < size)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	if (dst)
		*dst = '\0';
	return (dst_len + src_len);
}
