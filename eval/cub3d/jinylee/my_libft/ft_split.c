/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 15:17:34 by jinylee           #+#    #+#             */
/*   Updated: 2020/10/03 14:46:36 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_word_cnt(char const *s, char c)
{
	int len;

	len = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len++;
			while (*s && *s != c)
				s++;
		}
	}
	return (len);
}

char	**ft_error(char **ans)
{
	size_t	i;

	i = 0;
	while (ans[i])
	{
		free(ans[i]);
		i++;
	}
	return (0);
}

char	**char_copy(char const *s, char c, int cnt, char **ans)
{
	int		j;
	int		i;
	int		k;
	int		start;
	int		len;

	i = 0;
	j = -1;
	while (cnt > (++j))
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		len = i - start + 1;
		if (!(ans[j] = (char *)malloc(sizeof(char) * (len))))
			return (ft_error(ans));
		k = 0;
		while (--len)
			ans[j][k++] = s[start++];
		ans[j][k] = 0;
	}
	ans[j] = 0;
	return (ans);
}

char	**ft_split(char const *s, char c)
{
	int		cnt;
	char	**ans;

	if (s == 0)
		return (0);
	cnt = is_word_cnt(s, c);
	ans = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (ans == 0)
		return (0);
	ans = char_copy(s, c, cnt, ans);
	return (ans);
}
