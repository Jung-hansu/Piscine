/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:26:54 by junhelee          #+#    #+#             */
/*   Updated: 2022/01/16 20:27:00 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_error(void)
{
	write(1, "Error\n", 6);
}

int	exception(int *arr, int size)
{
	while (*arr)
	{
		if (!(*arr >= 1 && *arr <= size))
			return (0);
		arr++;
	}
	return (1);
}
