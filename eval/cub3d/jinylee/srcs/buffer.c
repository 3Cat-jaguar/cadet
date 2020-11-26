/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:29:42 by jinylee           #+#    #+#             */
/*   Updated: 2020/11/18 21:29:44 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_buf(t_info *info)
{
	int i;
	int j;

	i = 0;
	while (i < info->map.h)
	{
		j = 0;
		while (j < info->map.w)
		{
			info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
	info->mouse = 0;
}

void	free_buf(int **buf, int i)
{
	while (i > -1)
	{
		free(buf[i]);
		i--;
	}
}

int		**create_buf(int w, int h)
{
	int	**buf;
	int	i;

	i = 0;
	if (!(buf = (int **)malloc(sizeof(int*) * h)))
		return (0);
	while (i < h)
	{
		if (!(buf[i] = (int *)malloc(sizeof(int) * w)))
		{
			free_buf(buf, i);
			free(buf);
			return (0);
		}
		i++;
	}
	return (buf);
}

int		*load_image(t_info *info, char *path, t_img *img)
{
	img->img =
		mlx_xpm_file_to_image(info->mlx, path, &img->img_w, &img->img_h);
	img->data = (int *)mlx_get_data_addr(img->img,
									&img->bpp, &img->size_l, &img->endian);
	return (img->data);
}
