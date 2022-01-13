/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:38:11 by hanjung           #+#    #+#             */
/*   Updated: 2022/01/13 09:37:54 by hanjung          ###   ########.fr       */
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

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < size)
	{
		j = i;
		min = tab[i];
		while (j < size)
		{
			if (tab[j] < min)
			{
				swap(&tab[i], &tab[j]);
				min = tab[i];
			}
			j++;
		}
		i++;
	}
}
