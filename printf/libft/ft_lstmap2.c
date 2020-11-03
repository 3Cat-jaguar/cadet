/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:15:21 by ylee              #+#    #+#             */
/*   Updated: 2020/10/19 15:08:36 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
