/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:20:37 by ylee              #+#    #+#             */
/*   Updated: 2020/10/19 11:21:06 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (lst && *lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		if (tmp->content)
		{
			del(tmp->content);
			tmp->content = NULL;
		}
		if (tmp->next)
		{
			free(tmp->next);
			tmp->next = NULL;
		}
		free(tmp);
		tmp = NULL;
	}
}
