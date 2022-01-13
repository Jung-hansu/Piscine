/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:56:27 by hanjung           #+#    #+#             */
/*   Updated: 2022/01/13 12:10:47 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] += 'A' - 'a';
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
		if (!(str[i - 1] >= 'a' && str[i - 1] <= 'z'))
			if (!(str[i - 1] >= 'A' && str[i - 1] <= 'Z'))
				if (!(str[i - 1] >= '0' && str[i - 1] <= '9'))
					if (str[i] >= 'a' && str[i] <= 'z')
						str[i] += 'A' - 'a';
		i++;
	}
	return (str);
}
