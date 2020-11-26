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

#include "cub3d_bonus.h"

void	free_cub(t_cub *map)
{
	free(map->path_no);
	free(map->path_so);
	free(map->path_ea);
	free(map->path_we);
	free(map->path_s);
	free(map->path_f);
	free(map->path_c);
	free(map->path_ss);
	free(map->color_f);
	free(map->color_c);
	free_arr(map->map);
}

void	free_game(t_game *info)
{
	free_cub(&info->map);
	free(info->z_buf);
	free(info->r_dist);
	free(info->sprite);
	free_buf(info->buf, info->map.h - 1);
	free(info->buf);
}

int		free_out(t_game *info)
{
	destroy_img(info);
	free_game(info);
	system("killall afplay");
	exit(0);
	return (0);
}
