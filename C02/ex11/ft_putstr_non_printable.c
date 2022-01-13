/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:23:15 by hanjung           #+#    #+#             */
/*   Updated: 2022/01/13 13:54:59 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	change_hex(char *arr, int i)
{
	char	c;

	c = arr[i];							//마저 하기
}


void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 32 && str[i] <= 126))
		{
			write(1, "\\", 1);
			change_hex(str, i);
		}
		write(1, &str[i], 1);
		i++;
	}
}

int main(){
	char arr[]="Coucou\ntu vas bien ?";
	ft_putstr_non_printable(arr);
	return 0;
}
