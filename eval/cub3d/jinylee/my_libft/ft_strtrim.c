/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 21:35:52 by jinylee           #+#    #+#             */
/*   Updated: 2020/10/02 22:05:51 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ss1;
	int		start;
	int		end;
	int		len;

	if (s1 == 0 || set == 0)
		return ((char *)s1);
	end = ft_strlen(s1) - 1;
	start = 0;
	while (start <= end && ft_check(s1[start], set))
		start++;
	while (end >= 0 && ft_check(s1[end], set))
		end--;
	len = (end > start) ? end - start + 1 : 0;
	if (len <= 1)
		return (ft_strdup(""));
	ss1 = (char *)malloc(sizeof(char) * (len + 1));
	if (ss1 == 0)
		return (0);
	ft_strlcpy(ss1, s1 + start, len + 1);
	return (ss1);
}
