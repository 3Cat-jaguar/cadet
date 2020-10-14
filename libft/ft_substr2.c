/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 11:59:03 by ylee              #+#    #+#             */
/*   Updated: 2020/10/12 16:24:39 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*result;

	i = 0;
	if (!s)
		return (0);
	while (i < ((unsigned int)len + start) && s[i])
		i++;
	if (i <= start)
		i = 0;
	else
		i = i - start;
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (0);
	result[i] = '\0';
	if (i == 0)
		return (result);
	i = 0;
	while (i < (unsigned int)len && s[start + i])
	{
		result[i] = s[start + i];
		i++;
	}
	return (result);
}
