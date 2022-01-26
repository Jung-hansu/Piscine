/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woojlee <woojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 08:19:51 by woojlee           #+#    #+#             */
/*   Updated: 2022/01/26 08:53:03 by woojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_str_len(char *str);
int	ft_number_len(unsigned int number, int radix, int negative);
int	ft_is_space(char c);
int	ft_base_valid(char *str);

int	ft_get_idx_base(char *base, char match)
{
	int		idx;

	idx = 0;
	while (base[idx])
	{
		if (base[idx] == match)
			return (idx);
		idx++;
	}
	return (-1);
}

char	*ft_buffer_base(char *base, unsigned int number, int negative)
{
	int		idx;
	int		radix;
	int		len;
	char	*string;

	radix = ft_str_len(base);
	len = ft_number_len(number, radix, negative);
	string = (char *)malloc((len + 1) * sizeof(char));
	if (!string)
		return (0);
	if (negative)
		string[0] = '-';
	if (negative > 0)
		idx = 1;
	else
		idx = 0;
	while (idx < len)
	{
		string[len - (!negative) - idx++] = base[number % radix];
		number /= radix;
	}
	string[len] = '\0';
	return (string);
}

int	ft_get_result(char *nbr, char *base_from)
{
	int				resolved;
	int				radix;
	unsigned int	result;

	result = 0;
	radix = ft_str_len(base_from);
	while (1)
	{
		resolved = ft_get_idx_base(base_from, *nbr);
		if (resolved == -1)
			break ;
		result *= radix;
		result += resolved;
		nbr++;
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				minus;
	unsigned int	result;

	if (!ft_base_valid(base_from) || !ft_base_valid(base_to))
		return (NULL);
	minus = 1;
	while (ft_is_space(*nbr))
		nbr++;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*(nbr++) == '-')
			minus *= -1;
	}
	result = ft_get_result(nbr, base_from);
	if (result == 0)
		minus = 1;
	if (minus > 0)
		minus = 0;
	else
		minus = 1;
	return (ft_buffer_base(base_to, result, minus));
}
