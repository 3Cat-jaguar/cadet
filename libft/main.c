/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:50:00 by ylee              #+#    #+#             */
/*   Updated: 2020/10/07 11:28:26 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int		ft_strlcat(char *dst, const char *src, int size);

int		main(void)
{
	const char	*src;
	char		dst[1000];
	char		dst2[1000];
	int			i;
	int			size;
	
	dst[0] = 'h';
	dst[1] = 'e';
	dst[2] = 'l';
	dst[3] = 'l';
	dst[4] = 'o';
	dst[5] = '\0';
/*	dst[6] = 'u';
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
	dst[23] = '\0'; */
	src = "good morning";
	i = 0;
	while (dst[i])
	{
		dst2[i] = dst[i];
		i++;
	}
	dst2[i] = '\0';
	size = 8;
//	printf("%lu\n", strlen(src));
//	printf("%d\n", ft_strlen(s));
//	printf("%lu\n", strlcpy(dst, src, 0));
//	printf("%d\n", ft_strlcpy(dst2, src, 4));
	printf("dst_len = %lu , src_len = %lu , size = %d \n", strlen(dst), strlen(src), size);
	printf("strlcat : %lu\n", strlcat(dst, src, (size_t)size));
	printf("new_dst : %s\n", dst);
	printf("dst2_len = %lu , src_len = %lu , size = %d \n", strlen(dst2), strlen(src), size);
	printf("ft_strlcat : %d\n", ft_strlcat(dst2, src, size));
	printf("new_dst2 : %s\n", dst2);
	return (0);
}
