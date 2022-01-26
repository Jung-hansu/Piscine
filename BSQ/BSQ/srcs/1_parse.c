/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsong <tsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:48:29 by tsong             #+#    #+#             */
/*   Updated: 2022/01/25 21:50:17 by tsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	parse_map_info(t_map *map, char *info)
{
	int	ret;

	ret = parse_map_info_sub(map, info);
	if (!ret)
		free(map);
	free(info);
	return (ret);
}

char	*read_line(int fd, char *temp, int *size, int cnt)
{
	char	*line;
	char	c;
	int		idx;

	idx = -1;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
		{
			temp[idx] = 0;
			break ;
		}
		if (cnt + 1 == *size)
			temp = expand_size(temp, size);
		temp[cnt++] = c;
	}
	if (cnt == 0)
		return (free_line(temp));
	line = (char *)malloc(cnt);
	if (!line)
		exit(0);
	while (++idx < cnt)
		line[idx] = temp[idx];
	return (line);
}

t_map	*read_map(int fd, t_map	*map, int *size, int cnt)
{
	char	*line;
	char	*temp;
	int		idx;

	temp = (char *)malloc(sizeof(char) * *size);
	if (!temp || !parse_map_info(map, read_line(fd, temp, size, cnt)))
		return (0);
	map->arr = (char **)malloc(sizeof(char *) * map->y_len);
	idx = 0;
	map->x_len = 0;
	while (1)
	{
		line = read_line(fd, temp, size, cnt);
		if (!line)
			break ;
		if (!read_map_sub(&idx, map, line))
			return (0);
	}
	if (idx != map->y_len)
	{
		free_map(map, idx);
		return (0);
	}
	return (map);
}

t_map	*read_stdin(void)
{
	return (read_map(0, NULL, 0, 0));
}

t_map	*read_file(char *file)
{
	int		fd;
	t_map	*map;
	int		size;
	int		cnt;

	size = 1000;
	cnt = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		exit(0);
	return (read_map(fd, map, &size, cnt));
}
