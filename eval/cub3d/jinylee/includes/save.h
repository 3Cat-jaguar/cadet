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

#ifndef SAVE_H
# define SAVE_H

# include "cub3d.h"

# pragma pack(push, 1)

typedef struct		s_file_header
{
	unsigned short	bf_type;
	unsigned int	bf_size;
	unsigned short	bf_reserved_1;
	unsigned short	bf_reserved_2;
	unsigned int	bf_data_start;
}					t_file_header;

typedef struct		s_info_header
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
}					t_info_header;

typedef struct		s_bmp
{
	t_file_header	file_header;
	t_info_header	info_header;
}					t_bmp;

# pragma pack(pop)

int					create_bmp(t_info *info);

#endif
