/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:13:36 by rstarfir          #+#    #+#             */
/*   Updated: 2020/02/20 17:03:58 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		ft_close(void)
{
	exit(0);
	return (0);
}

int		key_press(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(0);
	return (0);
}

t_point		trans(t_point dot)
{
	int		new_x;
	int		new_y;
	int		n;

	n = 30;
	new_x = dot.x * cos(0.46373398) - dot.y * sin(0.46373398);
	new_y = -dot.y * sin(0.46373398) + dot.x * cos(0.46373398);
	/*dot.x = 900 + dot.x * n;
	dot.y = 350 + dot.y * n;*/
	dot.x = 900 + new_x; //* n;
	dot.y = 350 + new_y; //* n;
	return (dot);
}

void	draw_matrix(t_map *map, t_mlx *tmp)
{
	t_point ps;
	t_point pf;
	int		i;
	int		j;

	i = 0;
	ps.y = i;
	pf.y = i;
	while (i < map->y)
	{
		j = 0;
		ps.x = j;
		pf.x = j + 1;
		while(j < map->x)
		{
			pf.z = map->map[i][j].height;
			if (j + 1 < map->x)
				drawline(tmp, trans(ps), trans(pf));
				//drawline(tmp, ps, pf);
			pf.x = j;
			pf.y = i + 1;
			if (i + 1 < map->y)
				drawline(tmp, trans(ps), trans(pf));
				//drawline(tmp, ps, pf);
			j++;
			ps.x = j;
			pf.x = j + 1;
			pf.y = i;
		}
		i++;
		ps.y = i;
		pf.y = i;
	}
}

/*void	draw_circle(t_mlx *tmp)
{
	t_point	ps;
	t_point pf;
	int		sectors = 60;
	int		radius = 270;
	double	alpha = 0, beta = 360;
	double	step = 360 / sectors;

	printf("enter starting angle: ");
	scanf("%lf", &alpha);
	printf("enter ending angle: ");
	scanf("%lf", &beta);

	ps.x = 960;
	ps.y = 540; //10
	pf.x = 960 + cos(alpha) * radius;
	pf.y = 540 + sin(alpha) * radius; // 200
	printf("%d	%d\n", pf.x, pf.y);
	drawline(tmp, &ps, &pf);
	while (alpha < beta)
	{
		alpha += step;
		pf.x = 960 + (cos(PI / 180 * alpha) * radius);
		pf.y = 540 - (sin(PI / 180 * alpha) * radius); // 200
		drawline(tmp, &ps, &pf);
	}
}
*/
int image_init(t_map *map)
{
	t_mlx	tmp;
	int		x;

	x = 1;
	tmp.img.clr = 0xF07800;
	tmp.mlx = mlx_init();
	tmp.wndw = mlx_new_window(tmp.mlx, WIDTH, HEIGHT, "FDF");
	tmp.img.img_ptr = mlx_new_image(tmp.mlx, WIDTH, HEIGHT);
	tmp.img.data = (int *)mlx_get_data_addr(tmp.img.img_ptr, &tmp.img.bpp, &tmp.img.size_l, &tmp.img.endian);
//	draw_circle(&tmp);
	draw_matrix(map, &tmp);
	mlx_put_image_to_window(tmp.mlx, tmp.wndw, tmp.img.img_ptr, 0, 0);
	//mlx_key_hook(tmp.wndw, key_press, &tmp);
	mlx_hook(tmp.wndw, 2, 0L, key_press, &tmp);
	mlx_hook(tmp.wndw, 17, 0L, ft_close, &tmp);
	mlx_loop(tmp.mlx);
	return (0);
}
