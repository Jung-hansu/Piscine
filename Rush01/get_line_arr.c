/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:30:09 by junhelee          #+#    #+#             */
/*   Updated: 2022/01/16 20:30:19 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	*get_col_line_arr(int	*result_arr, int	idx, int	size)
{
	int	i;
	int	j;
	int	*line_arr;

	line_arr = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		j = (idx % size) + (size * i);
		line_arr[i] = result_arr[j];
		i ++;
	}
	return (line_arr);
}

int	*get_row_line_arr(int	*result_arr, int	idx, int	size)
{
	int	i;
	int	j;
	int	*line_arr;

	line_arr = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		j = (idx / size * size) + i;
		line_arr[i] = result_arr[j];
		i ++;
	}
	return (line_arr);
}

int	*reverse_arr(int	*line_arr, int	size)
{
	int	i;
	int	*reverse_arr;

	reverse_arr = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		reverse_arr[i] = line_arr[size - 1 - i];
		i ++;
	}
	return (reverse_arr);
}
