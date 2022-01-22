/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:58:40 by hanjung           #+#    #+#             */
/*   Updated: 2022/01/22 16:22:20 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
int	exception(char *base, int base_num)
{
	int	i;
	int	j;

	i = 0;
	if (base_num <= 1)
		return (1);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

void	rev_arr_order(char *arr, int i)
{
	int	j;
	int	tmp;

	j = 0;
	while (j < i / 2)
	{
		tmp = arr[j];
		arr[j] = arr[i - j - 1];
		arr[i - j - 1] = tmp;
		j++;
	}
}

void	change_base(int nbr, int base_num, char *base, char *result)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	if (nbr == -2147483648)
	{
		check = 1;
		nbr = 2147483647;
		write(1, "-", 1);
	}
	while (nbr > 0)
	{
		if (check-- > 0)
		{
			result[i++] = base[(nbr - base_num + 1) % base_num];
			nbr = (nbr - base_num + 1) / base_num + 1;
			continue ;
		}
		result[i] = base[nbr % base_num];
		nbr /= base_num;
		i++;
	}
	result[i] = 0;
	rev_arr_order(result, i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		base_num;
	char	result[50];

	i = 0;
	base_num = 0;
	result[0] = '0';
	while (base[base_num])
		base_num++;
	if (exception(base, base_num))
		return ;
	if (nbr < 0 && nbr != -2147483648)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	change_base(nbr, base_num, base, result);
	while (result[i++])
		write(1, &result[i - 1], 1);
}
