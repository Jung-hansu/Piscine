/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:32:35 by hanjung           #+#    #+#             */
/*   Updated: 2022/01/12 12:16:27 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(int i, int j, int k, int l)
{
	i += 48;
	j += 48;
	k += 48;
	l += 48;
	write(1, &k, 1);
	write(1, &l, 1);
	write(1, " ", 1);
	write(1, &i, 1);
	write(1, &j, 1);
}

void	ft_print_comb1(int k, int l)
{
	int	i;
	int	j;

	i = k;
	while (i <= 9)
	{
		if (i == k)
			j = l + 1;
		else
			j = 0;
		while (j <= 9)
		{
			putchar(i, j, k, l);
			if (!(k == 9 && l == 8))
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}

void	ft_print_comb2(void)
{
	int	k;
	int	l;

	k = 0;
	while (k <= 9)
	{
		l = 0;
		while (l <= 9 || (k == 9 && l == 6))
		{
			ft_print_comb1(k, l);
			l++;
		}
		k++;
	}
}
