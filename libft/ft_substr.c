/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:50:40 by hanjung           #+#    #+#             */
/*   Updated: 2022/03/23 21:47:55 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	char	*tmp;
	int		i;

	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!arr)
		return (0);
	tmp = arr;
	i = 0;
	while (i < (int)len)
	{
		*(tmp + i) = s[start + i];
		i++;
	}
	return (arr);
}
