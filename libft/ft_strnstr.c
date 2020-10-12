/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 18:35:41 by ylee              #+#    #+#             */
/*   Updated: 2020/10/12 13:46:11 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		cmp(const char *s1, const char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] && s2[idx])
	{
		if (s1[idx] != s2[idx])
			break ;
		idx++;
	}
	if (s1[idx - 1] == s2[idx - 1] && !s2[idx])
		return (idx);
	else
		return (0);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
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
			result = cmp(&s1[idx1], s2);
			if (result == 0 || idx1 + result - 1 >= n)
				return (0);
			else
				return (find);
		}
		idx1++;
	}
	return (0);
}
