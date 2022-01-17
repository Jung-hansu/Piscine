/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosong <yosong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:25:15 by yosong            #+#    #+#             */
/*   Updated: 2022/01/16 20:26:02 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	ft_putchar(char c);
int		get_flag(void);
int		check(int *result_arr, int *view_arr, int *index_arr, int size);

void	print_arr(int *arr, int size)
{
	char	c;
	int		*p;
	int		i;

	i = 0;
	p = arr;
	while (i < size * size)
	{
		c = arr[i] + '0';
		ft_putchar(c);
		if (i % size == size - 1)
			ft_putchar('\n');
		else
			ft_putchar(' ');
		i++;
	}
}

int	*get_view_arr(int *input_arr, int index, int size)
{
	int	*view_arr;

	view_arr = (int *)malloc(sizeof(int) * 4);
	view_arr[0] = *(input_arr + index % size);
	view_arr[1] = *(input_arr + size + index % size);
	view_arr[2] = *(input_arr + size * 2 + index / size);
	view_arr[3] = *(input_arr + size * 3 + index / size);
	return (view_arr);
}

void	bt(int *result_arr, int *input_arr, int index, int size)
{
	int	i;
	int	*view_arr;
	int	index_arr[2];

	if (index == size * size)
	{
		if (get_flag() == 1)
			print_arr(result_arr, size);
		return ;
	}
	else
	{
		i = 0;
		while (i++ < size)
		{
			view_arr = get_view_arr(input_arr, index, size);
			index_arr[0] = index;
			index_arr[1] = i;
			*(result_arr + index) = i;
			if (check(result_arr, view_arr, index_arr, size))
				bt(result_arr, input_arr, index + 1, size);
			*(result_arr + index) = 0;
		}
	}
}
