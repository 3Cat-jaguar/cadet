/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 10:11:27 by ylee              #+#    #+#             */
/*   Updated: 2020/10/14 11:54:50 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*trim(char *str, const char *set)
{
	int		check;

	check = 0;
	while (check == 0)
	{
		check = 1;
		idx_set = 0;
		while (set[idx_set])
		{
			if(str[0] == set[idx_set])
			{
				ft_memmove(str, str + 1, ft_strlen(str));
				check = 0;
			}
			if (str[ft_strlen(str) - 1] == set[idx_set])
			{
				str[ft_strlen(str) - 1] = '\0';
				check = 0;
			}
			idx_set++;
		}
	}
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		check;
	int		idx_set;
	char	*str;
	char	*result;

	if (!s1)
		return (0);
	else if (!set || ft_strlen(set) == 0)
		return ((char *)ft_strdup(s1));
	if (!(str = (char *)ft_strdup(s1)))
		return (0);
	str = trim(str, set);
	result = (char *)ft_strdup(str);
	if(!result)
		return (0);

	return (str);
}
