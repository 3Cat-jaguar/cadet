/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:20:37 by ylee              #+#    #+#             */
/*   Updated: 2020/10/19 13:55:07 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nxt;
	t_list	*now;

	if (!lst || !del)
		return ;
	nxt = *lst;
	*lst = NULL;
	while (nxt)
	{
		now = nxt;
		nxt = now->next;
		del(now->content);
		now->content = NULL;
		now->next = NULL;
		free(now);
		now = NULL;
	}
}
