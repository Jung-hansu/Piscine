/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:50:12 by sueshin           #+#    #+#             */
/*   Updated: 2022/01/23 21:57:36 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

extern t_dict	*g_start;
extern t_dict	*g_end;

void	ft_find_dict1(int num, int flag)
{
	t_dict	*newnode;

	newnode = g_start;
	if (num == 0)
		return ;
	while (newnode != NULL)
	{
		if (ft_atoi(newnode->num) == num)
		{
			if (flag == 1)
				ft_putchar(' ');
			ft_putstr(newnode->mean);
			break ;
		}
		else
			newnode = newnode->next;
	}
}

void	ft_find_dict2(char *num)
{
	t_dict	*cur;

	cur = g_start;
	while (cur != NULL)
	{
		if (!ft_strcmp(cur->num, num))
		{
			ft_putstr(" ");
			ft_putstr(cur->mean);
			return ;
		}
		else
			cur = cur->next;
	}
	write(2, "Dict Error\n", 11);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
