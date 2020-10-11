/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 18:14:59 by ylee              #+#    #+#             */
/*   Updated: 2020/10/11 18:18:27 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *str, int c, int n)
{
	int					i;
	unsigned char		uc;
	const unsigned char	*s;

	i = 0;
	uc = (unsigned char)c;
	s = str;
	while (i < n)
	{
		if (s[i] == uc)
			return ((void *)&s[i]);
		i++;
	}
	return (0);
}
