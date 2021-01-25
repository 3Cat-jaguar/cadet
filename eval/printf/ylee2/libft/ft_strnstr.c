/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 18:35:41 by ylee              #+#    #+#             */
/*   Updated: 2020/10/22 23:30:52 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	idx1;
	int		result;
	char	*find;

	idx1 = 0;
	find = (char *)s1;
	if (!s2[0])
		return ((char *)s1);
	while (idx1 < n && s1[idx1])
	{
		if (s1[idx1] == s2[0])
		{
			find = (char *)&s1[idx1];
			result = ft_strncmp(find, s2, ft_strlen(s2));
			if (result == 0 && idx1 - 1 + ft_strlen(s2) < n)
				return (find);
		}
		idx1++;
	}
	return (0);
}
