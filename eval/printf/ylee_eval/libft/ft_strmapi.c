/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:17:44 by ylee              #+#    #+#             */
/*   Updated: 2020/10/14 16:47:02 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		idx_s;
	char	*result;

	if (!s)
		return (0);
	result = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!result)
		return (0);
	idx_s = 0;
	while (s[idx_s])
	{
		result[idx_s] = f(idx_s, s[idx_s]);
		idx_s++;
	}
	return (result);
}
