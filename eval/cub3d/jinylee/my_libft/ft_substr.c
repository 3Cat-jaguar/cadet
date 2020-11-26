/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:07:33 by jinylee           #+#    #+#             */
/*   Updated: 2020/10/03 19:26:23 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	size_t	i;
	size_t	size;

	i = 0;
	if (s == 0)
		return (0);
	size = ft_strlen(s);
	if (size < start)
		return (ft_strdup(""));
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (ans == NULL)
		return (NULL);
	while (i < len && s[i + start])
	{
		ans[i] = s[start + i];
		i++;
	}
	ans[i] = 0;
	return (ans);
}
