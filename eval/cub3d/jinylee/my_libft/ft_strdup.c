/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:04:41 by jinylee           #+#    #+#             */
/*   Updated: 2020/10/03 12:32:53 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*ans;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (ans == 0)
		return (0);
	while (s1[i])
	{
		ans[i] = s1[i];
		i++;
	}
	ans[i] = 0;
	return (ans);
}
