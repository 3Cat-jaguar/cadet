/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 11:25:41 by ylee              #+#    #+#             */
/*   Updated: 2020/10/08 14:21:43 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	while (str[i])
	{
		if ((unsigned char)str[i] == uc)
			return ((char *)&str[i]);
		i++;
	}
	if ((unsigned char)str[i] == uc)
		return ((char *)&str[i]);
	else
		return ("(null)");
}
