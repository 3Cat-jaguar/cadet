/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 22:26:40 by jinylee           #+#    #+#             */
/*   Updated: 2020/10/03 16:33:16 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	f;
	int		i;

	i = 0;
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	f = (char)c;
	while (s[i])
	{
		if (s[i] == f)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
