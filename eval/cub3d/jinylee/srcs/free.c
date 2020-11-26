/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:28:29 by jinylee           #+#    #+#             */
/*   Updated: 2020/11/18 21:28:34 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map *map)
{
	free(map->path_no);
	free(map->path_so);
	free(map->path_ea);
	free(map->path_we);
	free(map->path_s);
	free(map->color_f);
	free(map->color_c);
	free_arr(map->map);
}

void	free_info(t_info *info)
{
	free_map(&info->map);
	free(info->z_buf);
	free(info->sprite);
	free(info->r_dist);
	free_buf(info->buf, info->map.h - 1);
	free(info->buf);
}

int		free_exit(t_info *info)
{
	destroy_image(info);
	free_info(info);
	exit(0);
	return (0);
}
