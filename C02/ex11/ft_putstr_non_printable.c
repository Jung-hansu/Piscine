/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:23:15 by hanjung           #+#    #+#             */
/*   Updated: 2022/01/17 10:48:07 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	change_hex(char c)
{
	if (c < 10)
		return (c + '0');
	return (c - 10 + 'a');
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 32 && str[i] <= 126))
		{
			write(1, "\\", 1);
			c = change_hex((str[i] + 256) % 256 / 16);
			write(1, &c, 1);
			c = change_hex((str[i] + 256) % 256 % 16);
			write(1, &c, 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
