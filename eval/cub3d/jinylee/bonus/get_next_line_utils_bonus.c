/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:38:41 by jinylee           #+#    #+#             */
/*   Updated: 2020/10/11 16:20:06 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strchrchr(char *s, int c)
{
	char	f;
	int		i;

	i = 0;
	f = (char)c;
	while (s[i])
	{
		if (s[i] == f)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strcpycpy(char *dst, char *src, size_t n)
{
	size_t	i;

	if (dst == 0 && src == 0)
		return (dst);
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*ft_strndupup(char *s)
{
	char	*ans;
	int		len;

	len = ft_strlen(s);
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (ans == 0)
		return (0);
	len = 0;
	while (s[len])
	{
		ans[len] = s[len];
		len++;
	}
	ans[len] = 0;
	return (ans);
}

char	*ft_strjoinjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new;

	if (s1 == 0 && s2 == 0)
		return (0);
	if (s1 == 0 || s2 == 0)
		return ((s1 == 0) ? ft_strndupup(s2) : ft_strndupup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (new == 0)
		return (0);
	ft_strcpycpy(new, s1, s1_len);
	free(s1);
	ft_strcpycpy(new + s1_len, s2, s2_len);
	new[s1_len + s2_len] = 0;
	return (new);
}
