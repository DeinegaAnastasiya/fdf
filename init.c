/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:30:33 by poatmeal          #+#    #+#             */
/*   Updated: 2020/02/25 19:52:25 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int			ft_close(void)
{
	exit(0);
	return (0);
}

/*void    flush_img(t_mlx *tmp)
{
	while 
}*/

int			key_press(int keycode, void *param, t_mlx *tmp)
{
	(void)param;
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
	{
		//flush_img(tmp);
		tmp->img.data[23 * WIDTH + 900] = tmp->img.clr;
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
	tmp.img.clr = 0xF07800;
	tmp.mlx = mlx_init();
	tmp.wndw = mlx_new_window(tmp.mlx, WIDTH, HEIGHT, "FDF");
	tmp.img.img_ptr = mlx_new_image(tmp.mlx, WIDTH, HEIGHT);
	tmp.img.data = (int *)mlx_get_data_addr(tmp.img.img_ptr,
	&tmp.img.bpp, &tmp.img.size_l, &tmp.img.endian);
	draw_matrix(map, &tmp, &zoom);
	mlx_put_image_to_window(tmp.mlx, tmp.wndw, tmp.img.img_ptr, 0, 0);
	mlx_hook(tmp.wndw, 2, 0L, key_press, &tmp);
	mlx_hook(tmp.wndw, 17, 0L, ft_close, &tmp);
	mlx_loop(tmp.mlx);
	return (0);
}
