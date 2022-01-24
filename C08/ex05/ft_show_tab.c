/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:33:35 by hanjung           #+#    #+#             */
/*   Updated: 2022/01/24 12:07:30 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	print_int(int num)
{
	int		n;
	int		result;
	int		nod;
	char	c;

	n = num;
	nod = 0;
	while (n > 0)
	{
		n /= 10;
		nod++;
	}
	while (nod--)
	{
		n = 0;
		result = num;
		while (n++ < nod)
			result /= 10;
		result %= 10;
		c = result + '0';
		write(1, &c, 1);
	}
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
