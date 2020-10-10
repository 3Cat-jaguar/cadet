/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:47:23 by ylee              #+#    #+#             */
/*   Updated: 2020/10/10 16:31:50 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, int n)
{
	int			i;
	char		*d;
	const char	*s;

	if (!dst && !src)
		return (0);
	d = dst;
	s = src;
	if (d < s)
	{
		i = 0;
		while (i < n)
		{
			*(d + i) = *(s + i);
			i++;
		}
	}
	else if (d > s)
	{
		while (--n >= 0)
			*(d + n) = *(s + n);
	}
	return (dst);
}
