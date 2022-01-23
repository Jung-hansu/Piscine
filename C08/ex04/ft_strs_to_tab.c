/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:28:01 by hanjung           #+#    #+#             */
/*   Updated: 2022/01/23 19:43:50 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int	i;
	int	j;
	t_stock_str a;
	t_stock_str *arr;

	a.size = 0;
	i = -1;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			a.size++;
			arr->str[j] = av[i][j];
		}
		arr->str[j] = 0;
		arr->copy = (char *)malloc(sizeof(char) * a.size);
		if (arr->copy == NULL)
			return (NULL);
		arr->copy = arr->str;
	}
}
