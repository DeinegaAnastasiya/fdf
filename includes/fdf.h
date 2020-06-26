

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"
# define PI 3.1415926535
# define WIDTH 1920
# define HEIGHT 1080
# define KEY_PAD_1 83
# define KEY_PAD_2 84
# define KEY_PAD_7 89
# define KEY_PAD_8 91
# define KEY_PAD_ADD 69
# define KEY_PAD_SUB 78
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define ROSE 0xffa5ea
# define BLYU 0x97b8ff
# define DARK 0x000099

typedef struct		s_data
{
	int				height;
	int				color;
}					t_data;

typedef struct		s_map
{
	t_data			**map;
	int				x;
	int				y;
}					t_map;

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

typedef struct 		s_view
{
	double			scale;
	int				iso;
	double			move_x;
	double			move_y;
	double			angle_x;
	double			angle_y;
	double			angle_z;
}					t_view;

typedef struct		s_mlx
{
	void			*mlx;
	void			*wndw;
	t_img			img;
	t_map			*map;
	t_view			view;
}					t_mlx;

typedef struct		s_point
{
	int				x;
	int				y;
	int				xi;
	int				yi;
	int				sy;
	int				sx;
	int				fy;
	int				fx;
	int				z; 
	int				x_sign;
	int				y_sign;
}					t_point;


void				drawline(t_mlx *tmp, t_point ps, t_point pf);
int					image_init(t_mlx *mlx);
void				draw_matrix(t_map *map, t_mlx *mlx);
void				color_init_h(t_map *map, t_mlx *tmp, int i, int j);
void				color_init_v(t_map *map, t_mlx *tmp, int i, int j);
int					ft_close(void);
void				horiz_check(t_map *map, int i, int j, t_point *pf);
int					start_vert(t_point *ps, int i, int *j);
void				start_horiz(t_point *ps, t_point *pf, int i, int j);
void				end_horiz(t_point *pf, int i, int j, t_mlx *tmp);
void				vert_check(t_map *map, int i, int j, t_point *pf);
int					parser_fdf(int fd, t_map *map, char *argv, char *line);
void				memory_allocation(int fd, t_map *map);
int					get_color(double size, int color1, int color2);

#endif
