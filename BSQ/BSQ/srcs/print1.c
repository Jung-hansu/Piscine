/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsong <tsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:48:50 by tsong             #+#    #+#             */
/*   Updated: 2022/01/25 21:50:15 by tsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	modify_map(t_map *map, t_square *square)
{
	int		i;
	int		j;
	char	full;

	full = map->full;
	i = square->y - square->len;
	while (++i <= square->y)
	{
		j = square->x - square->len;
		while (++j <= square->x)
			map->arr[i][j] = full;
	}
}

void	print(t_map *map, t_square *square)
{
	int		i;

	modify_map(map, square);
	i = -1;
	while (++i < map->y_len)
	{
		write(1, map->arr[i], map->x_len);
		write(1, "\n", 1);
	}
}

void	free_map(t_map *map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(map->arr[i]);
		i++;
	}
	free(map->arr);
	free(map);
}
