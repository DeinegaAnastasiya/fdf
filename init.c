/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:30:33 by poatmeal          #+#    #+#             */
/*   Updated: 2020/02/26 16:39:55 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int			ft_close(void)
{
	exit(0);
	return (0);
}
/* 
void		erase_image(t_mlx *tmp)
{
	int		i;

	i = 0;
	while (i < (HEIGHT * WIDTH - 1))
	{
		tmp->img.data[i] = 0x000000;
		i++;
	}
	mlx_put_image_to_window(tmp->mlx, tmp->wndw, tmp->img.img_ptr, 0, 0);
}
 */
void    change_pro(int keycode, t_map *map, t_mlx *tmp)
{
	t_view	zoom;

	// erase_image(tmp);
	if (keycode == 69)
	{
		//mlx_clear_window(ctrl->mlx, ctrl->wndw);
		//ft_bzero(tmp->img.data, WIDTH * HEIGHT * (tmp->img.bpp / 8));
		//mlx_put_image_to_window(tmp->mlx, tmp->wndw, tmp->img.img_ptr, 0, 0);
		zoom.scale = 35;
		zoom.iso = 1;
		draw_matrix(map, tmp, zoom);
		mlx_put_image_to_window(tmp->mlx, tmp->wndw, tmp->img.img_ptr, 0, 0);
	}
}

int			key_press(int keycode, t_map *map, t_mlx *tmp)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
	{
		change_pro(keycode, map, tmp);
		//tmp->img.data[23 * WIDTH + 900] = tmp->img.clr;
	}
	return (0);
}

void		color_init(t_map *map, t_mlx *tmp, int i, int j)
{
	if (map->map[i][j].color != -1)
		tmp->img.clr = map->map[i][j].color;
	else if (map->map[i][j].height != 0)
		tmp->img.clr = 0xffa5ea;
	else
		tmp->img.clr = 0x97b8ff;
	
}

int			image_init(t_map *map)
{
	t_mlx	tmp;
	int		x;
	t_view	zoom;

	x = 1;
	zoom.iso = 0;
	zoom.scale = 35;
	tmp.img.clr = 0xF07800;
	tmp.mlx = mlx_init();
	tmp.wndw = mlx_new_window(tmp.mlx, WIDTH, HEIGHT, "FDF");
	tmp.img.img_ptr = mlx_new_image(tmp.mlx, WIDTH, HEIGHT);
	tmp.img.data = (int *)mlx_get_data_addr(tmp.img.img_ptr,
	&tmp.img.bpp, &tmp.img.size_l, &tmp.img.endian);
	draw_matrix(map, &tmp, zoom);
	mlx_put_image_to_window(tmp.mlx, tmp.wndw, tmp.img.img_ptr, 0, 0);
	mlx_hook(tmp.wndw, 2, 0L, key_press, &tmp);
	mlx_hook(tmp.wndw, 17, 0L, ft_close, &tmp);
	mlx_loop(tmp.mlx);
	return (0);
}
