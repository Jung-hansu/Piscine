/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsong <tsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:47:33 by tsong             #+#    #+#             */
/*   Updated: 2022/01/25 21:50:19 by tsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	bsq(char *file)
{
	t_map		*map;
	t_square	*square;

	if (file)
		map = read_file(file);
	else
		map = read_stdin();
	if (!map)
	{
		ft_put_errmsg(ERR_MSG);
		return ;
	}
	square = find_bsq(map);
	if (!square->len)
		ft_put_errmsg(ERR_MSG);
	else
		print(map, square);
	free_map(map, map->y_len);
	free(square);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc == 1)
		bsq(0);
	else
	{
		i = 1;
		while (i < argc)
		{
			bsq(argv[i]);
			i++;
		}
	}
	return (0);
}
