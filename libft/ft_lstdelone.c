/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylee <ylee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:45:01 by ylee              #+#    #+#             */
/*   Updated: 2020/10/16 16:00:59 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*temp;

	temp = lst;
	if (temp)
	{
		if (lst->next)
			lst = lst->next;	
		del(temp->content);
		free(temp->next);
		temp->next = NULL;
		free(temp);
		temp = NULL;
	}
}
