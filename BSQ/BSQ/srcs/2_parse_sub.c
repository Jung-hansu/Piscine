/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sub1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsong <tsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:48:11 by tsong             #+#    #+#             */
/*   Updated: 2022/01/25 21:50:18 by tsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	is_valid_map_info(t_map *map)
{
	int	full;
	int	obst;
	int	empt;
	int	result;

	full = is_printable(map->full);
	obst = is_printable(map->obstacle);
	empt = is_printable(map->empty);
	result = full && obst && empt;
	return (result);
}

int	parse_map_info_sub(t_map *map, char *info)
{
	int	len;

	len = ft_strlen(info);
	if (!info || (len < 4))
		return (0);
	map->full = info[len - 1];
	map->obstacle = info[len - 2];
	map->empty = info[len - 3];
	if (map->empty == map->obstacle
		|| map->empty == map->full
		|| map->obstacle == map->full
		|| !is_valid_map_info(map))
		return (0);
	info[len - 3] = 0;
	map->y_len = ft_atoi(info);
	if (!(map->y_len))
		return (0);
	return (1);
}

char	*free_line(char *line)
{	
	free(line);
	return (0);
}

int	read_map_sub(int *idx, t_map *map, char *line)
{
	int	len;

	if (*idx == map->y_len || !ft_is_valid_map(line, map))
	{
		free(line);
		free_map(map, *idx);
		return (0);
	}
	len = ft_strlen(line);
	if (map->x_len == 0)
		map->x_len = len;
	if (len != map->x_len)
	{
		free(line);
		free_map(map, *idx);
		return (0);
	}
	map->arr[(*idx)++] = line;
	return (1);
}
