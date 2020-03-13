/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 20:36:06 by rstarfir          #+#    #+#             */
/*   Updated: 2020/03/05 15:41:30 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"
# include "map.h"
# define PI 3.1415926535
# define WIDTH 1920
# define HEIGHT 1080
# define KEY_PAD_1 83
# define KEY_PAD_2 84
# define SIZE 20
# define ROSE 0xffa5ea
# define BLYU 0x97b8ff

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	double			clr;
	double			clr2;
	int				bpp;
	int				size_l;
	int				endian;
}					t_img;

typedef struct		s_view
{
	int				scale;
	int				iso;
}					t_view;

typedef struct		s_mlx
{
	void			*mlx;
	void			*wndw;
	t_img			img;
	t_map			*map;
}					t_mlx;

typedef struct		s_point
{
	int				x;
	int				y;
	int				x2;
	int				y2;
	int				xi;
	int				yi;
	int				z;
	int				x_sign;
	int				y_sign;
}					t_point;

void				drawline(t_mlx *tmp, t_point ps, t_point pf);
int					image_init(t_map *map);
void				draw_matrix(t_map *map, t_mlx *tmp, t_view view);
void				color_init_h(t_map *map, t_mlx *tmp, int i, int j);
void				color_init_v(t_map *map, t_mlx *tmp, int i, int j);
void				change_pro1(int keycode, t_mlx *tmp);
void				change_pro2(int keycode, t_mlx *tmp);
int					ft_close(void);
void				horiz_check(t_map *map, int i, int j, t_point *pf);
int					start_vert(t_point *ps, int i, int *j);
void				start_horiz(t_point *ps, t_point *pf, int i, int j);
void				end_horiz(t_point *pf, int i, int j, t_mlx *tmp);
void				vert_check(t_map *map, int i, int j, t_point *pf);

#endif
