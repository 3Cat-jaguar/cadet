/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 19:38:44 by jinylee           #+#    #+#             */
/*   Updated: 2020/10/02 21:28:43 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *ans;

	ans = (void *)malloc(count * size);
	if (ans == 0)
		return (NULL);
	ft_memset(ans, 0, count * size);
	return (ans);
}
