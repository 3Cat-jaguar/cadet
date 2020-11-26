/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 02:46:57 by jinylee           #+#    #+#             */
/*   Updated: 2020/11/26 03:01:20 by jinylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include "key.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17
# define TEX_C					9
# define TEXW					64
# define TEXH					64

typedef struct	s_sprit
{
	double		x;
	double		y;
	int			num;
	int			order;
	double		dist;
	double		trans_x;
	double		trans_y;
	int			screen_x;
	int			sprite_w;
	int			sprite_h;
	int			start_x;
	int			start_y;
	int			end_x;
	int			end_y;
	int			del;
}				t_sprit;

typedef struct	s_ra
{
	double		camera_x;
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_h;
	int			draw_start;
	int			draw_end;
	int			tex_num;
}				t_ra;

typedef struct	s_cub
{
	int			w;
	int			h;
	int			c;
	int			f;
	int			is_nl;
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	char		*path_s;
	char		*path_f;
	char		*path_c;
	char		*path_ss;
	char		*color_f;
	char		*color_c;
	t_list		*map_lst;
	char		**map;
	size_t		map_width;
	size_t		map_height;
}				t_cub;

typedef struct	s_pic
{
	void		*img;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			img_w;
	int			img_h;
}				t_pic;

typedef struct	s_game
{
	char		direction;
	int			mouse;
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	void		*mlx;
	void		*win;
	double		move_speed;
	double		rot_speed;
	int			*tex[TEX_C];
	double		*z_buf;
	int			**buf;
	int			sprite_count;
	double		*r_dist;
	int			hp;
	t_ra		ray;
	t_cub		map;
	t_pic		img[TEX_C];
	t_pic		screen;
	t_sprit		*sprite;
}				t_game;

typedef struct	s_fs
{
	float	raydirx0;
	float	raydiry0;
	float	raydirx1;
	float	raydiry1;
	int		p;
	float	posz;
	float	rowdistance;
	float	floorstepx;
	float	floorstepy;
	float	floorx;
	float	floory;
	int		cellx;
	int		celly;
	int		tx;
	int		ty;
}				t_fs;

int				ft_arrlen(char **arr);
void			free_arr(char **arr);
int				**create_buf(int w, int h);
void			initbuf(t_game *info);
void			free_buf(int **buf, int i);
int				*loadimage(t_game *info, char *path, t_pic *img);

void			destroy_img(t_game *info);
void			ft_draw(t_game *info, int is_save);
void			load_tex(t_game *info, t_cub *map);

int				path_check(char *path);
int				error_chk(t_cub *map);
void			ft_swap(t_sprit *s, t_sprit *t);

void			free_cub(t_cub *map);
int				free_out(t_game *info);
void			free_game(t_game *info);

void			player_d(t_game *info, char direction);
int				player_p(t_game *info);
int				init_game(t_game *info);
void			init_pic(t_cub *map);

int				keypress(int key, t_game *info);
void			myturn(t_game *info, double angle);
int				my_mouse(int x, int y, t_game *s);

int				exit_game(t_game *info, int code, char const *str);
int				ft_loop(t_game *info);
int				ft_mlx(t_game *info);

int				check_wall(t_cub *map, size_t i, size_t j, size_t len);
int				check_cubfile(char *str);
int				check_char(t_cub *map);
int				check_cub(t_game *info);

int				check_null(t_cub *map);
void			input_lst(t_cub *map, char *line);
void			del(void *content);
int				map_make(t_cub *map);

void			raycasting(t_game *info);

int				path_input(t_cub *map, char **arr);
int				parsing_map(t_game *info, char *path);
int				arr_split(t_game *info, char *line);

void			buf_sprite(t_game *info, int stripe, int i, int y);
void			sprite_trans(t_game *info, int i);
void			sprite_draw(t_game *info, t_sprit *sprite, int i);
void			sprite_init(t_game *info, t_sprit *sprite, int i);
void			ft_sprite(t_game *info);

int				sprite_create(t_game *info);
void			coo_sprite(t_game *info);
int				cnt_sprite(t_game *info);
void			ft_sorting(t_game *info);
void			ft_distance(t_game *info);

void			ray_init(t_ra *ray, t_game *info, int x);
int				find_dir(char direction);
double			wall_cal(t_ra *ray, t_game *info);
int				tex_x_cal(t_ra *ray, t_game *info);
void			input_but(t_pic *img, t_ra *ray, t_game *info, int x);

int				ft_bonus(t_cub *map, char **arr);
void			draw_skyground(t_game *info, int w, int h);
void			make_tables(t_game *info);
int				distance_shade(int color, double distance);
int				ft_cnt(t_game *info, int count, int i, int j);

void			crossshot(t_game *s);
void			add_img(t_game *s);
void			del_s(t_game *s, int y, int x);
#endif
