/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woojlee <woojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:53:37 by woojlee           #+#    #+#             */
/*   Updated: 2022/01/22 12:22:33 by woojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_include_check(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i ++;
	}
	return (0);
}

int	ft_string_cnt(char *str, char *charset)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (!ft_include_check(*str, charset))
		{
			cnt++;
			while (*str && !ft_include_check(*str, charset))
				str++;
		}
		str++;
	}
	return (cnt);
}

void	ft_cpy(char *from, char *result, char *to)
{
	while (from < to)
		*(result++) = *(from++);
	*result = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	char	*from;
	int		s_idx;

	s_idx = 0;
	result = (char **)malloc(sizeof(char *) * ft_string_cnt(str, charset) + 1);
	if (result == NULL)
		return (NULL);
	while (*str)
	{
		if (!ft_include_check(*str, charset))
		{
			from = str;
			while (*str && !ft_include_check(*str, charset))
				str++;
			result[s_idx] = (char *)malloc(sizeof(char) * (str - from + 1));
			if (result[s_idx] == NULL)
				return (NULL);
			ft_cpy(from, result[s_idx], str);
			s_idx++;
		}
		str++;
	}
	result[s_idx] = 0;
	return (result);
}
