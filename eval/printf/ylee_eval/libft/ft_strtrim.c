/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 10:11:27 by ylee              #+#    #+#             */
/*   Updated: 2020/10/20 10:09:34 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_c_in_set(char c, char const *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (0);
		i++;
	}
	return (1);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		set_len;
	int		str_len;
	int		start;
	char	*str;
	char	*result;

	set_len = ft_strlen(set);
	if (!s1)
		return (0);
	if (!set || set_len == 0)
		return ((char *)ft_strdup(s1));
	start = 0;
	while (check_c_in_set(s1[start], set) == 0)
		start++;
	str = (char *)&s1[start];
	str_len = ft_strlen(str);
	while (str_len > 0 && check_c_in_set(str[str_len - 1], set) == 0)
		str_len--;
	result = (char *)ft_calloc(str_len + 1, sizeof(char));
	ft_strlcpy(result, str, str_len + 1);
	return ((char *)result);
}
