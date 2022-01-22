/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:00:20 by hanjung           #+#    #+#             */
/*   Updated: 2022/01/17 13:20:13 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_arr(char *str, char *to_find, int i, int *sp)
{
	int	j;

	j = 0;
	while (to_find[j++])
	{
		if (str[i + j - 1] == to_find[j - 1])
			*sp = i;
		else
		{
			*sp = -1;
			break ;
		}
	}
}

int	ft_lenstr(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	start_pt;
	int	*sp;

	i = 0;
	start_pt = -1;
	sp = &start_pt;
	if (!to_find[0])
		return (str);
	while (str[i] && ft_lenstr(str) >= ft_lenstr(to_find))
	{
		if (str[i] == to_find[0])
			check_arr(str, to_find, i, sp);
		if (*sp >= 0)
			break ;
		i++;
	}
	if (*sp >= 0)
		return (&str[*sp]);
	return (0);
}
