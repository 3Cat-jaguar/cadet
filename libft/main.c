/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 16:50:00 by ylee              #+#    #+#             */
/*   Updated: 2020/10/16 13:55:31 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int		main(void)
{
	t_list *l = ft_lstnew((void *)"abc");
	t_list *n = ft_lstnew((void *)"efg");
	ft_lstadd_front(&l, n);
	if (l == n)
	{
		printf("ok\n");
		printf("%s\n", (char *)(l->next->content));
	}
	else
		printf("error\n");

/*

	int     c = L'ø';

	write(1, &(char)c, 1);	



	ft_split("abc,def,ghi,,,j,,",',');

	
	
	printf("%s\n", ft_itoa(10));


	char *s1 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ";
    char *s2 = "Hello \t  Please\n Trim me !";
	char *ret = ft_strtrim(s1, " \n\t");
	printf("%s\n", s2);
	printf("---\n");
	printf("%s\n", ret);	

	char	*s1 = "\xff";
	char	*s2 = "\0";
	printf("%d\n", strncmp(s1, s2, 6));
	printf("%d\n", ft_strncmp(s1, s2, 6));

	s1 = "\250";
	s2 = "\0";
	printf("%d\n", strncmp(s1, s2, 6));
	printf("%d\n", ft_strncmp(s1, s2, 6));

	char str[] = "memmove can be very useful......";

	ft_memmove(str + 20, str + 15, 11);
	printf("%s\n", str);

	printf("%s\n",strchr("hello", 's'));
	printf("%s\n",ft_strchr("hello", 's'));

	char ptr[1000] = {0};
	char ptr2[1000] = {0};
	int		value = 3;
	size_t	num = 10;
	int		i;

	memset((void *)&ptr[0], value, num);
	i = 0;
	while (ptr[i] != 0)
	{
		printf("%d\n", ptr[i]);
		i++;
	}
	printf("%d\n", i);

	ft_memset((void *)&ptr2[0], value, num);
	i = 0;
	while (ptr2[i] != 0)
	{
		printf("%d\n", ptr2[i]);
		i++;
	}
	printf("%d\n", i);

	printf("%s\n",strchr("īœ˙ˀ˘¯ˇ¸¯.œ«‘––™ª•¡¶¢˜ˀ",L'–'));
	printf("%s\n",ft_strchr("īœ˙ˀ˘¯ˇ¸¯.œ«‘––™ª•¡¶¢˜ˀ",L'–'));

	printf("%d\n", atoi("-2147483648"));
	printf("%d\n", ft_atoi("-2147483648"));
	printf("%d\n", atoi("–9223372036854775810"));
	printf("%d\n", ft_atoi("–9223372036854775810"));
	printf("%d\n", atoi("9223372036854775810"));
	printf("%d\n", ft_atoi("9223372036854775810"));

	printf("%d\n",isalpha(50));
	printf("%d\n",ft_isalpha(50));
	printf("%d\n",isalpha('A'));
	printf("%d\n",ft_isalpha('A'));
	printf("%d\n",isalpha('a'));
	printf("%d\n",ft_isalpha('a'));
	printf("%d\n",isalpha('B'));
	printf("%d\n",ft_isalpha('B'));
	printf("%d\n",isalpha('b'));
	printf("%d\n",ft_isalpha('b'));
	printf("%d\n",isalpha('F'));
	printf("%d\n",ft_isalpha('F'));
	printf("%d\n",isalpha('g'));
	printf("%d\n",ft_isalpha('g'));

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
	dst[23] = '\0'; 
	src = "good morning";
	i = 0;
	while (dst[i])
	{
		dst2[i] = dst[i];
		i++;
	}
	dst2[i] = '\0';
	size = 8;
	printf("%lu\n", strlen(src));
	printf("%d\n", ft_strlen(s));
	printf("%lu\n", strlcpy(dst, src, 0));
	printf("%d\n", ft_strlcpy(dst2, src, 4));
	printf("dst_len = %lu , src_len = %lu , size = %d \n", strlen(dst), strlen(src), size);
	printf("strlcat : %lu\n", strlcat(dst, src, (size_t)size));
	printf("new_dst : %s\n", dst);
	printf("dst2_len = %lu , src_len = %lu , size = %d \n", strlen(dst2), strlen(src), size);
	printf("ft_strlcat : %d\n", ft_strlcat(dst2, src, size));
	printf("new_dst2 : %s\n", dst2);
*/	
	return (0);
}
