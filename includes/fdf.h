/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 20:36:06 by rstarfir          #+#    #+#             */
/*   Updated: 2020/02/26 19:18:45 by poatmeal         ###   ########.fr       */
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

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				clr;
	int				bpp;
	int				size_l;
	int				endian;
}					t_img;

typedef struct 		s_view
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
void				color_init(t_map *map, t_mlx *tmp, int i, int j);
void    			change_pro1(int keycode, t_mlx *tmp);
void    			change_pro2(int keycode, t_mlx *tmp);
int					ft_close(void);

#endif
