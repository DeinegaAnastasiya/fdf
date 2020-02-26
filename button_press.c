/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:20:48 by poatmeal          #+#    #+#             */
/*   Updated: 2020/02/26 19:21:20 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int			ft_close(void)
{
	exit(0);
	return (0);
}

void		change_pro1(int keycode, t_mlx *tmp)
{
	t_view	view;

	view.scale = 35;
	if (keycode == KEY_PAD_1)
	{
		ft_bzero(tmp->img.data, WIDTH * HEIGHT * (tmp->img.bpp / 8));
		mlx_put_image_to_window(tmp->mlx, tmp->wndw, tmp->img.img_ptr, 0, 0);
		view.iso = 1;
		draw_matrix(tmp->map, tmp, view);
		mlx_put_image_to_window(tmp->mlx, tmp->wndw, tmp->img.img_ptr, 0, 0);
	}
}

void		change_pro2(int keycode, t_mlx *tmp)
{
	t_view	view;

	view.scale = 35;
	if (keycode == KEY_PAD_2)
	{
		ft_bzero(tmp->img.data, WIDTH * HEIGHT * (tmp->img.bpp / 8));
		mlx_put_image_to_window(tmp->mlx, tmp->wndw, tmp->img.img_ptr, 0, 0);
		view.iso = 0;
		draw_matrix(tmp->map, tmp, view);
		mlx_put_image_to_window(tmp->mlx, tmp->wndw, tmp->img.img_ptr, 0, 0);
	}
}
