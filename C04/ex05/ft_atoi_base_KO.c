/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:48:36 by hanjung           #+#    #+#             */
/*   Updated: 2022/01/22 20:48:19 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_base(char *base)
{
	int	i;
	int	j;
	int	base_num;

	i = 0;
	base_num = 0;
	while (base[base_num])
		base_num++;
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
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (1);
		i++;
	}
	return (0);
}

int	num_of_printable(char *str, char *base, int index)
{
	int	i;
	int	j;
	int	base_num;

	base_num = 0;
	while (base[base_num])
		base_num++;
	i = -1;
	while (str[index + ++i])
	{
		j = -1;
		while (++j < base_num)
			if (base[j] == str[index + i])
				break ;
		if (j == base_num)
			return (i);
	}
	return (i);
}

int	change_dec(char *num, char *base)
{
	int	i;
	int	j;
	int	base_num;
	int	result;

	base_num = 0;
	result = 0;
	while (base[base_num])
		base_num++;
	j = -1;
	while (num[++j])
	{
		i = -1;
		while (++i < base_num)
			if (base[i] == num[j])
				result = (result * base_num) + i;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		j;
	int		sign;
	char	num[50];

	i = 0;
	sign = 1;
	if (check_base(base))
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	j = 0;
	while (j < num_of_printable(str, base, i))
	{
		num[j] = str[i + j];
		j++;
	}
	return (sign * change_dec(num, base));
}
