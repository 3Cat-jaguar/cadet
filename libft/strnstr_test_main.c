#include "libft.h"
#include <stdio.h>
#include <string.h>

int		main(void)
{
	printf("%s\n", strnstr("abcdefghijk", "abcde", 3));
	printf("%s\n", ft_strnstr("abcdefghijk", "abcde", 3));
	
	printf("%s\n", strnstr("","",3));
	printf("%s\n", ft_strnstr("","",3));
	
	printf("%s\n", strnstr("abcabcdefg", "abcde", 30));
	printf("%s\n", ft_strnstr("abcabcdefg", "abcde", 30));

	return (0);
}
