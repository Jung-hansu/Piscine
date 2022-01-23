/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:25:27 by hanjung           #+#    #+#             */
/*   Updated: 2022/01/22 21:23:07 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*arr;

	i = 0;
	while (src[i])
		i++;
	arr = (char *)malloc(sizeof(char) * i);
	if (src == NULL)
		return (0);
	arr = src;
	return (arr);
}
