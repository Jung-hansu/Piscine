/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:10:35 by hanjung           #+#    #+#             */
/*   Updated: 2022/03/23 21:47:55 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	int	i;
	int	j;
	int	dstlen;

	i = 0;
	j = 0;
	while (dest[i] && i < (int)destsize)
		i++;
	dstlen = i;
	while (src[j] && i + j + 1 < (int)destsize)
		dest[i++] = src[j++];
	dest[i] = 0;
	return (dstlen + ft_strlen(src));
}
