/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:12:05 by hanjung           #+#    #+#             */
/*   Updated: 2022/01/22 18:49:43 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	print_argv(char **argv, int index)
{
	int	i;

	i = -1;
	while (argv[index][++i])
		write(1, &argv[index][i], 1);
	write(1, "\n", 1);
}

int	cmp_argv(char *str1, char *str2)
{
	int	i;
	int	cmp;

	i = 0;
	while (str1[i] && str1[i] == str2[i])
		i++;
	cmp = str1[i] - str2[i];
	return (cmp);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
		{
			if (cmp_argv(argv[i], argv[j]) > 0)
			{
				tmp = argv[i];
				argv[i] = argv[j];
				argv[j] = tmp;
			}				
		}
	}
	i = 0;
	while (++i < argc)
		print_argv(argv, i);
	return (0);
}
