/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:13:36 by rstarfir          #+#    #+#             */
/*   Updated: 2020/02/26 20:25:48 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_point		trans(t_point dot, t_view view)
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
	}
	else if (view.iso == 0)
	{
		new_x = dot.x;
		new_y = dot.y;
	}
	dot.x = 780 + new_x;
	dot.y = 170 + new_y;
	return (dot);
}

void		draw_matrix(t_map *map, t_mlx *tmp, t_view view)
{
	t_point ps;
	t_point pf;
	int		i;
	int		j;

	i = 0;
	while (i < map->y)
	{
		ps.y = i;
		j = 0;
		while (j < map->x)
		{
			ps.x = j;
			pf.x = j + 1;
			pf.y = i;
			color_init(map, tmp, i, j);
			if (j < map->x - 1)
			{
				ps.z = map->map[i][j].height;
				if (j + 1 < map->x)
					pf.z = map->map[i][j + 1].height;
				else
					pf.z = map->map[i][j].height;
				drawline(tmp, trans(ps, view), trans(pf, view));
			}
			pf.x = j;
			pf.y = i + 1;
			if (i < map->y - 1)
			{
				ps.z = map->map[i][j].height;
				if (i + 1 < map->y)
					pf.z = map->map[i + 1][j].height;
				else
					pf.z = map->map[i][j].height;
				drawline(tmp, trans(ps, view), trans(pf, view));
			}
			j++;
		}
		i++;
	}
}

/* 
void		draw_matrix(t_map *map, t_mlx *tmp, t_view view)
{
	t_point p[2];
	int		i[2];

	while (i[0] < map->y && (i[0] = -1) &&
			(p[0].y = ++i[0]))
		while (i[1] < map->x && (i[1] = -1))
		{
			p[0].x = ++i[1];
			p[1].x = i[1] + 1;
			p[1].y = i[0];
			color_init(map, tmp, i[0], i[1]);
			if (i[1] < map->x - 1 && (p[0].z = map->map[i[0]][i[1]].height))
			{
				p[1].z = (i[1] + 1 < map->x ? map->map[i[0]][i[1] + 1].height :\
							map->map[i[0]][i[1]].height);
				drawline(tmp, trans(p[0], view), trans(p[1], view));
			}
			p[1].x = i[1];
			p[1].y = i[0] + 1;
			if (i[0] < map->y - 1 && (p[0].z = map->map[i[0]][i[1]].height))
			{
				p[1].z = (i[0] + 1 < map->y ? map->map[i[0]][i[1] + 1].height :\
							map->map[i[0]][i[1]].height);
				drawline(tmp, trans(p[0], view), trans(p[1], view));
			}
		}
} */
