/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:50:54 by hanjung           #+#    #+#             */
/*   Updated: 2022/01/23 10:45:08 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	strs_len(int size, char **strs)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
			j++;
		len += j;
	}
	return (len);
}

int	sep_len(char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		index;
	int		sep_i;
	char	*arr;

	arr = (char *)malloc(sizeof(char) * (strs_len(size, strs) + sep_len(sep)));
	if (!arr)
		return (0);
	if (size == 0)
		return (arr);
	i = -1;
	index = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
			arr[index++] = strs[i][j++];
		sep_i = 0;
		if (i != size - 1)
			while (sep[sep_i])
				arr[index++] = sep[sep_i++];
	}
	arr[index] = 0;
	return (arr);
}
