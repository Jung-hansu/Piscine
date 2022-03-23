/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:18:12 by hanjung           #+#    #+#             */
/*   Updated: 2022/03/23 21:47:55 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_memmove(void *dest, const void *src, size_t num)
{
	size_t	i;

	if (!(dest) && !(src))
		return (NULL);
	if (dest < src)
	{
		i = 0;
		while (i < num)
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i++];
	}
	else
	{
		i = num;
		while (i-- > 0)
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	}
	return (dest);
}
