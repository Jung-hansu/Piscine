/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:27:46 by hanjung           #+#    #+#             */
/*   Updated: 2022/01/12 11:41:11 by hanjung          ###   ########.fr       */
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

void	ft_rev_int_tap(int *tap, int size)
{
	int	i;

	i = 0;
	while (i <= (size / 2) - 1)
	{
		swap(&tap[i], &tap[size - 1 - i]);
		i++;
	}
}
