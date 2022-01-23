/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:23:31 by hanjung           #+#    #+#             */
/*   Updated: 2022/01/22 21:33:11 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;
	int	min_val;

	if (min >= max)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * (max - min + 1));
	i = 0;
	min_val = min;
	while (i < max - min)
		arr[i++] = min_val++;
	return (arr);
}
