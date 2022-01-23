/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 09:14:33 by hanjung           #+#    #+#             */
/*   Updated: 2022/01/22 20:21:28 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_queens(int *map)
{
	int		i;
	char	n;

	i = 0;
	while (i < 10)
	{
		n = map[i] + '0';
		write(1, &n, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	check_queens(int *map, int col_num)
{
	int	i;

	if (col_num == 0)
		return (1);
	i = 0;
	while (++i <= col_num)
	{
		if (map[col_num - i] == map[col_num]
			|| map[col_num - i] + i == map[col_num]
			|| map[col_num - i] - i == map[col_num])
			return (0);
	}
	return (1);
}

void	bt(int *map, int col_num, int *num_ways)
{
	int	queen;

	if (col_num == 10)
	{
		print_queens(map);
		(*num_ways)++;
		return ;
	}
	else
	{
		queen = -1;
		while (++queen <= 9)
		{
			map[col_num] = queen;
			if (check_queens(map, col_num))
				bt(map, col_num + 1, num_ways);
			map[col_num] = 0;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	map[10];
	int	i;
	int	ways;
	int	*num_ways;

	i = -1;
	ways = 0;
	num_ways = &ways;
	while (++i < 10)
		map[i] = 0;
	bt(map, 0, num_ways);
	return (ways);
}
