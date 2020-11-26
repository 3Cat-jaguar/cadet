/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 04:27:05 by jinylee           #+#    #+#             */
/*   Updated: 2020/10/03 19:35:36 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*next;

	if (lst == 0 || f == 0)
		return (0);
	head = 0;
	while (lst)
	{
		if ((next = ft_lstnew((*f)(lst->content))) == 0)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, next);
		next = next->next;
		lst = lst->next;
	}
	return (head);
}
