/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woojlee <woojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 08:17:28 by woojlee           #+#    #+#             */
/*   Updated: 2022/01/26 09:06:40 by woojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_str_len(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

int	ft_total_len(char **strings, int size, int sep_length)
{
	int	final_length;
	int	index;

	final_length = 0;
	index = 0;
	while (index < size)
	{
		final_length += ft_str_len(strings[index]);
		final_length += sep_length;
		index++;
	}
	final_length -= sep_length;
	return (final_length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_len;
	int		index;
	char	*dest;
	char	*string;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	total_len = ft_total_len(strs, size, ft_str_len(sep));
	string = (char *)malloc((total_len + 1) * sizeof(char));
	if (!string)
		return (0);
	dest = string;
	index = 0;
	while (index < size)
	{
		ft_strcpy(dest, strs[index]);
		dest += ft_str_len(strs[index]);
		if (index++ < size - 1)
		{
			ft_strcpy(dest, sep);
			dest += ft_str_len(sep);
		}
	}
	*dest = '\0';
	return (string);
}
