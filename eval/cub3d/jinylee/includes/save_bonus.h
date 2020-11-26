/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 02:47:19 by jinylee           #+#    #+#             */
/*   Updated: 2020/11/26 02:47:21 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVE_BONUS_H
# define SAVE_BONUS_H

# include "cub3d_bonus.h"

# pragma pack(push, 1)

typedef struct		s_file_head
{
	unsigned short	bf_type;
	unsigned int	bf_size;
	unsigned short	bf_reserved_1;
	unsigned short	bf_reserved_2;
	unsigned int	bf_data_start;
}					t_file_head;

typedef struct		s_info_head
{
	unsigned int	bi_size;
	int				bi_width;
	int				bi_height;
	unsigned short	bi_planes;
	unsigned short	bi_bpp;
	unsigned int	bi_compression;
	unsigned int	bi_size_image;
	int				bi_xppm;
	int				bi_yppm;
	unsigned int	bi_color_used;
	unsigned int	bi_color_important;
}					t_info_head;

typedef struct		s_bmps
{
	t_file_head	file_header;
	t_info_head	info_header;
}					t_bmps;

# pragma pack(pop)

int					make_bmp(t_game *info);

#endif
