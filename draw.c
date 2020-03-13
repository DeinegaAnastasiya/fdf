/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 20:32:49 by rstarfir          #+#    #+#             */
/*   Updated: 2020/03/13 13:32:28 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		get_color(int size, int r, int color1, int color2)
{
	int		red;
	int		green;
	int		blue;

	red = (size - r) * (color1 >> 16 & 0xFF) + r * (color2 >> 16 & 0xFF);
	green = (size - r) * (color1 >> 8 & 0xFF) + r * (color2 >> 8 & 0xFF);
	blue = (size - r) * (color1 & 0xFF) + r * (color2 & 0xFF);
	return (red << 16 | green << 8 | blue);
}

int		get_color1(t_point *d, int r, int color1, int color2)
{
	int		color;
	double	size;

	size = sqrt(pow(d->x, 2) + pow(d->y, 2));
	color = get_color(size, r, color1, color2);
	return (color);
}

void	abtuse(t_mlx *tmp, t_point *d, t_point pf, int err)
{
	int		i;

	i = 0;
	while (d->yi != pf.y)
	{
		if ((d->xi >= 0) && (d->xi < WIDTH - 1) &&
		(d->yi >= 0) && (d->yi < HEIGHT - 1))
		{
			i++;
			tmp->img.data[d->yi * WIDTH + d->xi] = get_color1(d, i, tmp->img.clr, tmp->img.clr2);
		}
		if ((pf.x >= 0) && (pf.x < WIDTH - 1) &&
		(pf.y >= 0) && (pf.y < HEIGHT - 1))
			tmp->img.data[pf.y * WIDTH + pf.x] = tmp->img.clr2;
		err += d->x;
		if ((err * 2) >= d->y)
		{
			d->xi += d->x_sign;
			err -= d->y;
		}
		d->yi += d->y_sign;
	}
}

void	acute(t_mlx *tmp, t_point *d, t_point pf, int err)
{
	int		i;

	i = 0;
	while (d->xi != pf.x)
	{
		if ((d->xi >= 0) && (d->xi < WIDTH - 1) &&
		(d->yi >= 0) && (d->yi < HEIGHT - 1))
		{
			i++;
			tmp->img.data[d->yi * WIDTH + d->xi] = get_color1(d, i, tmp->img.clr, tmp->img.clr2);
		}
		if ((pf.x >= 0) && (pf.x < WIDTH - 1) &&
		(pf.y >= 0) && (pf.y < HEIGHT - 1))
			tmp->img.data[pf.y * WIDTH + pf.x] = tmp->img.clr2;
		err += d->y;
		if ((err * 2) >= d->x)
		{
			d->yi += d->y_sign;
			err -= d->x;
		}
		d->xi += d->x_sign;
	}
}

void	drawline(t_mlx *tmp, t_point ps, t_point pf)
{
	t_point	d;
	int		err;

	d.yi = ps.y;
	d.xi = ps.x;
	err = 0;
	d.x = abs(pf.x - ps.x);
	d.y = abs(pf.y - ps.y);
	d.y_sign = (ps.y < pf.y) ? 1 : -1;
	d.x_sign = (ps.x < pf.x) ? 1 : -1;
	if (d.x >= d.y)
		acute(tmp, &d, pf, err);
	else
		abtuse(tmp, &d, pf, err);
}
