/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:25:57 by hanjung           #+#    #+#             */
/*   Updated: 2022/01/26 12:16:23 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	ft_malloc2(char *str, char **arr, int size)
{
	int	i;
	int	str_size;

	str_size = ft_strlen(str);
	i = -1;
	while (++i < size + 1)
		arr[i] = (char *)malloc(sizeof(char) * (str_size + 1));
}

char	**ft_malloc(char *str, char *charset)
{
	int	i;
	int j;
	int	size;
	char **arr;

	size = 0;
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (charset[++j])
			if (str[i] == charset[j])
				size++;
	}
	arr = (char **)malloc(sizeof(char) * (size + 2) * (ft_strlen(str) + 1));
	if (!arr)
		return (NULL);
	ft_malloc2(str, arr, size);
	i = -1;
	while (++i < size + 1)
		if (!arr[i])
			return (NULL);
	return (arr);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		result_idx;
	char	**result;

	result = ft_malloc(str, charset);
	if (!result)
		return (NULL);
	*result = str;
	i = -1;
	result_idx = 0;
	while (str[++i])
	{
		j = -1;
		while (charset[++j])
		{
			if (str[i] == charset[j])
			{
				*(result[result_idx] + i) = 0;
				result_idx++;
				*(result + result_idx) = (str + i + 1);
			}
		}
	}
	result[result_idx + 1] = 0;
	return (result);
}

#include <stdio.h>
int main()
{
	int i = 0;
	for(;i < 5; i++)
	printf("%s\n",ft_split("hello, world!","oed")[i]);
}
