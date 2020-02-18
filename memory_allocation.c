/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_allocation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:32:47 by poatmeal          #+#    #+#             */
/*   Updated: 2020/02/17 18:20:38 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/map.h"

int			count_number(char *line)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	if (line[i] != ' ')
	{
		i++;
		n++;
	}
	while (line[i])
	{
		if (line[i] == ' ')
			if (line[i + 1] != ' ' && line[i + 1] != '\0')
				n++;
		i++;
	}
	return (n);
}

void		memory_allocation(int fd, t_map *map)
{
	char	*line;
	int		n;
	int		i;
	int		count;

	n = 0;
	i = 1;
	count = 0;
	while (get_next_line(fd, &line) > 0)
	{
		n = count_number(line);
		i++;
		free(line);
	}
	close(fd);
	map->y = i;
	map->x = n;
	map->map = (t_data **)malloc(sizeof(t_data *) * i + 1);
	while (count < i)
	{
		map->map[count] = (t_data *)malloc(sizeof(t_data) * n + 1);
		count++;
	}
	map->map[count] = NULL;
}
