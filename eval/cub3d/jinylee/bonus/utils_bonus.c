/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:29:52 by jinylee           #+#    #+#             */
/*   Updated: 2020/11/18 21:29:53 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int					path_check(char *path)
{
	int	fd;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (1);
	close(fd);
	return (0);
}

unsigned int		color_atoi(char *color)
{
	char			**arr;
	unsigned int	tmp;
	int				i;

	i = 0;
	tmp = 0;
	arr = ft_split(color, ',');
	if (ft_arrlen(arr) != 3)
		return (0);
	while (i < 3)
	{
		tmp = tmp * 256 + ft_atoi(arr[i]);
		free(arr[i]);
		i++;
	}
	free(arr);
	return (tmp);
}

int					error_chk(t_cub *map)
{
	if (path_check(map->path_no) || path_check(map->path_so) ||
	path_check(map->path_we) || path_check(map->path_ea) ||
	path_check(map->path_s))
		return (-1);
	if (!(map->f = (int)color_atoi(map->color_f))
		|| !(map->c = (int)color_atoi(map->color_c)))
		return (-1);
	return (0);
}

void				ft_swap(t_sprit *s, t_sprit *t)
{
	s->x = t->x;
	s->y = t->y;
	s->num = t->num;
	s->dist = t->dist;
	s->del = t->del;
}
