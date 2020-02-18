/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:40:38 by poatmeal          #+#    #+#             */
/*   Updated: 2020/02/17 18:19:47 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "libft.h"
# include <stdio.h>

typedef struct		s_data
{
	void			*point;
	int				height;
	int				color;
	struct s_data	*next;
}					t_data;

typedef struct		s_map
{
	t_data			**map;
	int				x;
	int				y;
}					t_map;

int					parser_fdf(int fd, t_map *map, char *argv, char *line);
void				memory_allocation(int fd, t_map *map);

#endif
