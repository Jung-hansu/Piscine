/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:27:15 by junhelee          #+#    #+#             */
/*   Updated: 2022/01/19 12:26:51 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_ok_view(int *view, int size)
{
	int	min_arr[4];
	int	max_arr[4];
	int	i;

	i = -1;
	while (i++ < 3)
	{
		min_arr[i] = 0;
		max_arr[i] = 0;
	}
	i = -1;
	while (i++ < size * 4 - 1)
	{
		if (view[i] == 1)
			min_arr[i / size]++;
		if (view[i] == size)
			max_arr[i / size]++;
	}
	i = -1;
	while (i++ < 3)
	{
		if (min_arr[i] > 1 || max_arr[i] > 1)
			return (0);
	}
	return (1);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' \
			|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	get_len_str(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int	get_arr_size_and_check_error(char *str)
{
	char	*p;
	int		len;
	int		arr_size;

	p = str;
	len = get_len_str(str);
	arr_size = 0;
	if (!(*str >= '0' && *str <= '9') && !is_space(*str))
		return (-1);
	while (*p)
	{
		if (*p >= '0' && *p <= '9')
		{
			if (p != (str + len - 1))
				if (!is_space(*(p + 1)))
					return (-1);
			arr_size++;
		}
		else if (!is_space(*p))
			return (-1);
		p++;
	}
	return (arr_size);
}

int	*change_int_arr(char *str, int arr_size)
{
	int	*arr;
	int	i;
	int	j;

	arr = (int *)malloc(sizeof(int) * arr_size);
	i = 0;
	j = 0;
	while (i < arr_size)
	{
		if ('0' <= str[j] && str[j] <= '9')
			arr[i++] = str[j] - '0';
		j++;
	}
	return (arr);
}
