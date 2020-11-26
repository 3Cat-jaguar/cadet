/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:56:14 by jinylee           #+#    #+#             */
/*   Updated: 2020/10/03 13:27:20 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new;

	if (s1 == 0 && s2 == 0)
		return (0);
	if (s1 == 0 || s2 == 0)
		return ((s1 == 0) ? ft_strdup(s2) : ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (new == 0)
		return (0);
	ft_memcpy(new, s1, s1_len);
	free((char *)s1);
	ft_memcpy(new + s1_len, s2, s2_len);
	free((char *)s2);
	new[s1_len + s2_len] = 0;
	return (new);
}
