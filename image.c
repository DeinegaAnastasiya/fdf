/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:13:36 by rstarfir          #+#    #+#             */
/*   Updated: 2020/02/27 12:07:51 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		trans(t_point dot, t_view view, t_map *map)
{
	double		new_x;
	double		new_y;

	new_x = 0.0;
	new_y = 0.0;
	dot.x = dot.x * view.scale;
	dot.y = dot.y * view.scale;
	dot.z = dot.z * view.scale;
	if (view.iso == 1)
	{
		new_x = (dot.x - dot.y) * cos(0.46373398);
		new_y = -dot.z + (dot.x + dot.y) * sin(0.46373398);
		dot.x = (WIDTH / 2 - map->x / 4 * view.scale) + new_x;
		dot.y = (HEIGHT / 2 - map->y / 2 * view.scale) + new_y;
	}
	else if (view.iso == 0)
	{
		new_x = dot.x;
		new_y = dot.y;
		dot.x = (WIDTH / 2 - map->x / 2 * view.scale) + new_x;
		dot.y = (HEIGHT / 2 - map->y / 2 * view.scale) + new_y;
	}
	return (dot);
}

void		draw_matrix(t_map *map, t_mlx *tmp, t_view view)
{
	t_point ps;
	t_point pf;
	int		i;
	int		j;

	i = -1;
	while (++i < map->y && (!start_vert(&ps, i, &j)))
		while (++j < map->x)
		{
			start_horiz(&ps, &pf, i, j);
			color_init(map, tmp, i, j);
			if (j < map->x - 1)
			{
				ps.z = map->map[i][j].height;
				horiz_check(map, i, j, &pf);
				drawline(tmp, trans(ps, view, map), trans(pf, view, map));
			}
			end_horiz(&pf, i, j);
			if (i < map->y - 1)
			{
				ps.z = map->map[i][j].height;
				vert_check(map, i, j, &pf);
				drawline(tmp, trans(ps, view, map), trans(pf, view, map));
			}
		}
}
