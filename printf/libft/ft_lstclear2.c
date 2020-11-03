/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee </var/mail/ylee>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:48:04 by ylee              #+#    #+#             */
/*   Updated: 2020/10/19 10:10:26 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_del(void *content)
{
	    free(content);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst)
	{
		temp = *lst;
		del(temp->content);
		temp->content = NULL;
		lst = &(temp->next);
/*
		if (temp->next)
		{
			free(temp->next);
			temp->next = NULL;
		}
*/
	}
}

void	check_done(t_list *lst)
{
	if (lst)
		printf("%s\n", (char *)lst->content);
	else
		printf("NULL\n");
}

void	get_memory_str(char **str, char *content)
{
	int	len;
	
	len = 0;
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	len = ft_strlen(content);
	*str = (char *)malloc(sizeof(char) * (len + 1));
	*str = content;
}

int     main(void)
{
	    t_list  *one;
		t_list  *two;
		t_list  *thr;
		t_list  *four;
		t_list  *lst;

		char	*str;
		str = NULL;
		get_memory_str(&str, "one");
		one = ft_lstnew((void *)str);
		get_memory_str(&str, "two");
		two = ft_lstnew((void *)str);
		get_memory_str(&str, "three");
		thr = ft_lstnew((void *)str);
		get_memory_str(&str, "four");
		four = ft_lstnew((void *)str);
		one->next = two;
		two->next = thr;
		thr->next = four;
		four->next = NULL;
		lst = one;
		ft_lstclear(&thr, &ft_del);
		check_done(one);
		check_done(two);
		check_done(thr);
		check_done(four);
		return (0);
}
