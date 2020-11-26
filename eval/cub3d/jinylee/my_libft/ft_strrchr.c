/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:02:04 by jinylee           #+#    #+#             */
/*   Updated: 2020/10/03 16:34:47 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	f;
	int		len;

	len = ft_strlen(s);
	if (c == 0)
		return ((char *)s + len);
	f = (char)c;
	while (len >= 0)
	{
		if (s[len] == f)
			return ((char *)s + len);
		len--;
	}
	return (0);
}
