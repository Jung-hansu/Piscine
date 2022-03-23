/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:25:05 by hanjung           #+#    #+#             */
/*   Updated: 2022/03/23 21:47:55 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_memcmp(const void *p1, const void *p2, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		if (*((unsigned char *)p1 + i) != *((unsigned char *)p2 + i))
			return (*((unsigned char *)p1 + i) - *((unsigned char *)p2 + i));
		i++;
	}
	return ((void *)0);
}
