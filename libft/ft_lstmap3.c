/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:15:21 by ylee              #+#    #+#             */
/*   Updated: 2020/10/19 15:39:28 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*f(void *content)
{
	if (content)
		return ("OK !");
	else
		return (0);
}

void	del(void *content)
{
	if (content)
		free(content);
	content = NULL;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*now;

	if (!lst || !f || !del)
		return (0);
	tmp = lst;
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		now = ft_lstnew(f(lst->content));
		if (now)
			ft_lstadd_back(&new, now);
		else
		{
			ft_lstclear(&new, del);
			return (0);
		}
	}
	lst = tmp;
	return (new);
}

int		main(void)
{
	t_list	*l = ft_lstnew(ft_strdup(" 1 2 3 "));
	t_list	*ret;

	l->next = ft_lstnew(ft_strdup("ss"));
	l->next->next = ft_lstnew(ft_strdup("-_-"));
	ret = ft_lstmap(l, &f, &del);
	printf("%s\n",(char *)l->content);
	printf("%s\n",(char *)l->next->content);
	printf("%s\n",(char *)l->next->next->content);
	printf("%s\n",(char *)ret->content);
	printf("%s\n",(char *)ret->next->content);
	printf("%s\n",(char *)ret->next->next->content);
	if (ret->next->next->next)
		printf("%s\n",(char *)ret->next->next->next->content);
	else
		printf("NULL\n");
	return (0);
}
