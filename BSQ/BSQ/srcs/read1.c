/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsong <tsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:49:03 by tsong             #+#    #+#             */
/*   Updated: 2022/01/25 21:50:14 by tsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*expand_size(char *src, int *size)
{
	char	*ret;

	ret = (char *)malloc(*size << 1);
	if (!ret)
		exit(0);
	ft_strncpy(ret, src, *size);
	*size <<= 1;
	free(src);
	return (ret);
}

int	ft_atoi(char *str)
{
	int	num;
	int	i;

	if (*str == '0')
		return (0);
	num = 0;
	i = 0;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num);
}

int	ft_is_valid_map(char *line, t_map *map)
{
	while (*line)
	{
		if (*line != map->empty && *line != map->obstacle)
			return (0);
		line++;
	}
	return (1);
}
