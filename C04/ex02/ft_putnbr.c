/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:28:02 by hanjung           #+#    #+#             */
/*   Updated: 2022/01/17 14:28:09 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putnbr(int nb)
{
	int	size;
	int	arr[10];

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	size = ft_count(arr, nb);
	while (size-- > 0)
		printnum(arr[size]);
}
