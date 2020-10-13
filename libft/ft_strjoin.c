/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 09:44:24 by ylee              #+#    #+#             */
/*   Updated: 2020/10/13 09:47:41 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*result;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
	{
		i = ft_strlen(s2) + 1;
		result = (char *)malloc(sizeof(char) * i);
		while
	}

}
