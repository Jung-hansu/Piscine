/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:47:42 by sueshin           #+#    #+#             */
/*   Updated: 2022/01/23 21:56:40 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

extern t_dict	*g_start;
extern t_dict	*g_end;

char	*ft_strndup(char *str, int len)
{
	int		i;
	char	*result;

	i = 0;
	result = (char *)malloc(len * (sizeof(char) + 1));
	if (result == NULL)
		return (NULL);
	while (str[i] != '\0' && i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*str_check(char *str)
{
	char	*result;
	int		negative;
	int		size;
	char	*start;

	negative = 1;
	result = 0;
	size = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	while (*str == '0' && *(str + 1) != 0)
		str++;
	start = str;
	while (*str && *str >= '0' && *(str++) <= '9')
		size++;
	if (negative == -1)
		return (0);
	return (ft_strndup(start, size));
}

int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res);
}

void	add_node(char *nbr, char *str)
{
	t_dict	*newnode;

	newnode = (t_dict *)malloc(sizeof(t_dict));
	if (!newnode)
		return ;
	newnode->num = nbr;
	newnode->mean = str;
	newnode->next = NULL;
	if (g_start == NULL)
	{
		g_start = newnode;
		g_end = newnode;
	}
	else
	{
		g_end->next = newnode;
		g_end = newnode;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
