/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:30:13 by jinylee           #+#    #+#             */
/*   Updated: 2020/11/18 21:30:15 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int			check_null(t_cub *map)
{
	if (map->path_no && map->path_so && map->path_we &&
		map->path_ea && map->path_s && map->color_f &&
		map->color_c && map->h && map->w)
		return (0);
	return (1);
}

void		input_lst(t_cub *map, char *line)
{
	t_list	*new;

	if (map->map_width < ft_strlen(line))
		map->map_width = ft_strlen(line);
	new = ft_lstnew(ft_strndupup(line));
	ft_lstadd_back(&map->map_lst, new);
	map->map_height++;
}

void		del(void *content)
{
	free((char *)content);
}

char		*padding(int len)
{
	int		i;
	char	*pad;

	i = 0;
	if (!(pad = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	pad[len] = 0;
	while (i < len)
	{
		pad[i] = ' ';
		i++;
	}
	return (pad);
}

int			map_make(t_cub *map)
{
	int		i;
	t_list	*head;

	i = 0;
	head = map->map_lst;
	if (!(map->map = (char **)malloc(sizeof(char *) * (map->map_height + 1))))
		return (-1);
	map->map[map->map_height] = 0;
	while (head)
	{
		map->map[i] = ft_strjoin(ft_strndupup((char *)(head->content)),
			padding(map->map_width - ft_strlen(head->content)));
		head = head->next;
		i++;
	}
	ft_lstclear(&(map->map_lst), &del);
	return (0);
}
