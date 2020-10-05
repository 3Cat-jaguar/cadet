/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:50:00 by ylee              #+#    #+#             */
/*   Updated: 2020/10/05 16:44:04 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int		strlcpy(char *dst, const char *src, int size);

int		main(void)
{
	const char	*src;
	char		dst[1000];
	
	dst[0] = 'h';
	dst[1] = 'i';
	dst[2] = ' ';
	dst[3] = 'j';
	dst[4] = 'a';
	dst[5] = 'g';
	dst[6] = 'u';
	dst[7] = 'a';
	dst[8] = 'r';
	dst[9] = '!';
	dst[10] = '!';
	dst[11] = ' ';
	dst[12] = 'I';
	dst[13] = ' ';
	dst[14] = 'l';
	dst[15] = 'o';
	dst[16] = 'v';
	dst[17] = 'e';
	dst[18] = ' ';
	dst[19] = 'y';
	dst[20] = 'o';
	dst[21] = 'u';
	dst[22] = '!';
	dst[23] = '\n';
	s = "hello world";
	printf("%lu\n", strlen(s));
	printf("%lu\n", ft_strlen(s));
	return (0);
}
