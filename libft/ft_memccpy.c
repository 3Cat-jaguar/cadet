/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 18:01:35 by ylee              #+#    #+#             */
/*   Updated: 2020/10/11 18:11:13 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memccpy(void *dst, const void *src, int c, int n)
{
	int					i;
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		uc;

	i = 0;
	d = dst;
	s = src;
	uc = (unsigned char)c;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == uc)
			return ((void *)&d[i + 1]);
		i++;
	}
	return (0);
}
