/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:07:10 by hanjung           #+#    #+#             */
/*   Updated: 2022/01/17 10:07:11 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(int *arr, int n)
{
	int		i;
	char	arr1;

	i = 0;
	while (i < n)
	{
		arr1 = arr[i];
		arr1 += 48;
		write(1, &arr1, 1);
		i++;
	}
}

void	check_arr(int *arr, int n)
{
	int	i;
	int	check[10];

	i = -1;
	while (i++ < n - 1)
		check[i] = 0;
	i = -1;
	while (i++ < n - 2)
	{
		if (arr[n - 1 - i] > 9 - i)
		{
			arr[n - 2 - i]++;
			check[n - 1 - i] = 1;
		}
	}
	i = 0;
	while (i++ < n - 1)
		if (check[i])
			arr[i] = arr[i - 1] + 1;
}

void	ft_print_combn(int n)
{
	int	i;
	int	arr[10];

	i = 0;
	while (i < n)
	{
		arr[i] = i;
		i++;
	}
	while (arr[0] <= 10 - n)
	{
		i = 0;
		print_num(arr, n);
		arr[n - 1]++;
		check_arr(arr, n);
		if (!(arr[0] == 11 - n))
			write(1, ", ", 2);
	}
}
