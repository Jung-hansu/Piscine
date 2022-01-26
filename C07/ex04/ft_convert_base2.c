/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woojlee <woojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 08:20:22 by woojlee           #+#    #+#             */
/*   Updated: 2022/01/26 09:41:07 by woojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_len(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

int	ft_is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ');
}

int	ft_base_valid(char *str)
{
	char	*curr;
	int		idx;
	int		jidx;

	curr = str;
	if (str == 0 || ft_str_len(str) <= 1)
		return (0);
	while (*curr)
	{
		if (ft_is_space(*curr) || *curr == '+' || *curr == '-')
			return (0);
		curr++;
	}
	idx = 0;
	while (idx < curr - str)
	{
		jidx = idx + 1;
		while (jidx < curr - str)
			if (str[idx] == str[jidx++])
				return (0);
		idx++;
	}
	return (1);
}

int	ft_number_len(unsigned int number, int radix, int negative)
{
	unsigned int	len;

	if (negative > 0)
		len = 1;
	else
		len = 0;
	while (1)
	{
		len++;
		if (number / radix == 0)
			break ;
		number /= radix;
	}
	return (len);
}
