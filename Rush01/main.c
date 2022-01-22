/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:30:31 by junhelee          #+#    #+#             */
/*   Updated: 2022/01/19 12:26:58 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
int		bt(int *result_arr, int *input_arr, int index, int size);
int		exception(int *arr, int size);
void	print_error(void);
int		get_flag(void);
int		get_arr_size_and_check_error(char *str);
int		*change_int_arr(char *str, int arr_size);
int		is_ok_view(int *view, int size);

int	check_error(int *view, int view_size, int size)
{
	if (view_size <= 0 || view_size % 4 != 0)
	{
		print_error();
		return (0);
	}
	if (!is_ok_view(view, size))
	{
		print_error();
		return (0);
	}
	return (1);
}

int	check_argc(int argc)
{
	if (argc != 2)
	{
		print_error();
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	*map;
	int	*view;
	int	size;
	int	view_size;

	if (!check_argc(argc))
		return (0);
	view_size = get_arr_size_and_check_error(argv[1]);
	size = view_size / 4;
	map = (int *)malloc(sizeof(int) * size * size);
	i = -1;
	while (i++ < size * size - 1)
		map[i] = 0;
	view = change_int_arr(argv[1], view_size);
	if (!check_error(view, view_size, size))
	{
		return (0);
	}
	if (exception(view, size))
		bt(map, view, 0, size);
	if (get_flag() == 1 || !exception(view, size))
		print_error();
	free(map);
	free(view);
	return (0);
}
