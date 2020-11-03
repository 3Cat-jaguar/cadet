/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 11:59:03 by ylee              #+#    #+#             */
/*   Updated: 2020/10/14 10:03:09 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	s_len;
	char			*result;

	if (!s)
		return (0);
	s_len = (unsigned int)ft_strlen(s);
	if (s_len <= start)
		result = (char *)ft_strdup("");
	else if (s_len < (start + (unsigned int)len))
		result = (char *)ft_strdup(&s[start]);
	else
	{
		result = (char *)ft_calloc(len + 1, sizeof(char));
		if (!result)
			return (0);
		ft_strlcpy(result, &s[start], len + 1);
	}
	if (!result)
		return (0);
	return (result);
}
