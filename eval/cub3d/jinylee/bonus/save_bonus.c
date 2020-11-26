/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <jinylee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:29:22 by jinylee           #+#    #+#             */
/*   Updated: 2020/11/18 21:29:24 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save_bonus.h"
#include "cub3d_bonus.h"

void		file_header(t_file_head *header, unsigned int size)
{
	header->bf_type = 0x4D42;
	header->bf_size = size;
	header->bf_reserved_1 = 0;
	header->bf_reserved_2 = 0;
	header->bf_data_start = 54;
}

void		info_header(t_info_head *header, int width, int height, int bpp)
{
	header->bi_size = 40;
	header->bi_width = width;
	header->bi_height = height;
	header->bi_planes = 1;
	header->bi_bpp = bpp;
	header->bi_compression = 0;
	header->bi_size_image = 0;
	header->bi_xppm = 0;
	header->bi_yppm = 0;
	header->bi_color_used = 0;
	header->bi_color_important = 0;
}

int			make_bmp(t_game *info)
{
	t_bmps	bmp;
	int		fd;
	int		index;

	file_header(&bmp.file_header, info->map.w * info->map.h *
		sizeof(int) + sizeof(t_bmps));
	info_header(&bmp.info_header, info->map.w, info->map.h, info->screen.bpp);
	fd = open("screen.bmp", O_WRONLY | O_CREAT, S_IRWXG | S_IRWXU | S_IRWXO);
	if (fd > 0)
	{
		index = info->map.h - 1;
		write(fd, &bmp, sizeof(bmp));
		while (index >= 0)
		{
			write(fd, info->buf[index], info->map.w * sizeof(int));
			index--;
		}
		close(fd);
	}
	else
		return (exit_game(info, 1, "ERROR\nsave error\n"));
	return (0);
}
