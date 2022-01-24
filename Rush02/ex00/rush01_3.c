/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:52:20 by sueshin           #+#    #+#             */
/*   Updated: 2022/01/23 21:56:50 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

extern t_dict	*g_start;
extern t_dict	*g_end;

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	extract_num(char *num, int flag, int idx)
{
	int		num_len;
	int		size;
	char	three_num[3];

	num_len = str_len(num);
	size = num_len;
	if (num[0] == '0')
		ft_find_dict0(0);
	while (++idx < (size - 1) / 3 + 1)
	{
		three_num[0] = '0';
		three_num[1] = '0';
		three_num[2] = '0';
		while (1)
		{
			three_num[(3 - (num_len % 3)) % 3] = num[size - num_len];
			num_len--;
			if (num_len % 3 == 0)
			{
				ft_print_hundred(ft_atoi(three_num), num_len / 3, flag);
				flag = 1;
				break ;
			}
		}
	}
}

void	ft_print_hundred(int nbr, int count, int flag)
{
	char	*bignum;

	if (nbr / 100 > 0)
	{
		ft_find_dict1(nbr / 100, flag);
		flag = 1;
		ft_find_dict1(100, flag);
	}
	nbr %= 100;
	if (nbr < 20 || nbr % 10 == 0)
		ft_find_dict1(nbr, flag);
	else
	{
		ft_find_dict1(nbr - nbr % 10, flag);
		ft_find_dict1(nbr % 10, flag);
	}
	if (count != 0)
	{
		bignum = ft_set_bignum(count);
		ft_find_dict2(bignum);
		free(bignum);
	}
}

char	*ft_set_bignum(int count)
{
	char	*bignum;
	int		idx;

	idx = 0;
	bignum = (char *)malloc(sizeof(char) * (count * 3 + 2));
	if (!bignum)
		return (NULL);
	bignum[0] = '1';
	while (++idx <= count * 3)
		bignum[idx] = '0';
	bignum[idx] = 0;
	return (bignum);
}

void	ft_find_dict0(int num)
{
	t_dict	*newnode;

	newnode = g_start;
	while (newnode != NULL)
	{
		if (ft_atoi(newnode->num) == num)
		{
			ft_putstr(newnode->mean);
			break ;
		}
		else
			newnode = newnode->next;
	}
}
