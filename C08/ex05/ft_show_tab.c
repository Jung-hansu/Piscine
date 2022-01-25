/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:33:35 by hanjung           #+#    #+#             */
/*   Updated: 2022/01/25 13:42:22 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	printnum(int a)
{
	a = a + 48;
	write(1, &a, 1);
}

int	ft_count(int *arr, int a)
{
	int	i;

	i = 0;
	while (a != 0)
	{
		arr[i] = a % 10;
		a = a / 10;
		i++;
	}
	return (i);
}

void	print_int(int nb)
{
	int	size;
	int	arr[10];

	if (nb == 0)
	{
		write(1, "0\n", 2);
		return ;
	}
	size = ft_count(arr, nb);
	while (size-- > 0)
		printnum(arr[size]);
	write(1, "\n", 1);
}

void	print_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		print_str(par[i].str);
		print_int(par[i].size);
		print_str(par[i].copy);
		i++;
	}
}
