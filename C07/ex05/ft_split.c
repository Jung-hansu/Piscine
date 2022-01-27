/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:25:57 by hanjung           #+#    #+#             */
/*   Updated: 2022/01/27 11:20:16 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	get_size(char *str, char *charset)
{
	int	size;

	size = 0;
	while (*str)
	{
		if (!check_sep(*str, charset))
		{
			size++;
			while (*str && !check_sep(*str, charset))
				str++;
		}
		str++;
	}
	return (size);
}

void	ft_strcpy(char *dest, char *start, char *fin)
{
	while (start < fin)
		*(dest++) = *(start++);
	*dest = 0;
}

char	**ft_split(char *str, char *charset)
{
	int		size;
	int		i;
	char	**result;
	char	*temp;

	i = 0;
	size = get_size(str, charset);
	result = (char **)malloc(sizeof(char *) * (size + 1));
	while (*str)
	{
		if (!check_sep(*str, charset))
		{
			temp = str;
			while (*str && !check_sep(*str, charset))
				str++;
			result[i] = (char *)malloc(sizeof(char) * (str - temp + 1));
			ft_strcpy(result[i], temp, str);
			i++;
		}
		str++;
	}
	result[i] = 0;
	return (result);
}
