/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:38:11 by hanjung           #+#    #+#             */
/*   Updated: 2022/01/12 11:37:41 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tap(int *tap, int size)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < size)
	{
		j = i;
		min = tap[i];
		while (j < size)
		{
			if (tap[j] < min)
			{
				swap(&tap[i], &tap[j]);
				min = tap[i];
			}
			j++;
		}
		i++;
	}
}
