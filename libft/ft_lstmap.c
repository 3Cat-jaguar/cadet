/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:15:21 by ylee              #+#    #+#             */
/*   Updated: 2020/10/19 16:07:27 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*now;

	if (!lst || !f)
		return (0);
	tmp = lst;
	new = NULL;
	while (lst)
	{
		now = ft_lstnew(f(lst->content));
		if (now)
			ft_lstadd_back(&new, now);
		else
		{
			ft_lstclear(&new, del);
			return (0);
		}
		lst = lst->next;
	}
	lst = tmp;
	return (new);
}
