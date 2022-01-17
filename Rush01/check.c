#include <unistd.h>
#include <stdlib.h>

int	*get_col_line_arr(int *result_arr, int idx, int size);
int	*get_row_line_arr(int *result_arr, int idx, int size);
int	*reverse_arr(int *line_arr, int size);

int	_check_line_max(int	*arr, int	size)
{
	int	count;
	int	max;
	int	i;

	count = 1;
	max = arr[0];
	i = 0;
	while (i < size)
	{
		if (max == size)
			break ;
		if (arr[i] == 0)
		{
			count ++;
			max ++;
		}
		if (max < arr[i])
		{
			count ++;
			max = arr[i];
		}
		i++;
	}
	return (count);
}

int	_check_line_min(int	*arr, int	size)
{
	int	i;
	int	count;
	int	max;

	i = 0;
	count = 1;
	max = arr[0];
	while (i < size && arr[i] != 0)
	{
		if (arr[i] > max)
		{
			count++;
			max = arr[i];
		}
		i++;
	}
	return (count);
}

int	check_line(int	*line_arr, int	view, int size)
{
	int	min;
	int	max;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (line_arr[i] == line_arr[j] && line_arr[i] != 0)
				return (0);
			j ++;
		}
		i ++;
	}
	min = _check_line_min(line_arr, size);
	max = _check_line_max(line_arr, size);
	if (min <= view && view <= max)
		return (1);
	else
		return (0);
}

int	check(int	*result_arr, int	*view_arr, int	*index_arr, int	size)
{
	int	i;
	int	*line_arr[4];
	int	result;

	i = 0;
	result = 0;
	line_arr[0] = get_col_line_arr(result_arr, index_arr[0], size);
	line_arr[1] = reverse_arr(line_arr[0], size);
	line_arr[2] = get_row_line_arr(result_arr, index_arr[0], size);
	line_arr[3] = reverse_arr(line_arr[2], size);
	while (i < 4)
	{
		result = check_line(line_arr[i], view_arr[i], size);
		if (result == 0)
			return (0);
		free(line_arr[i]);
		i ++;
	}
	free(view_arr);
	return (1);
}
