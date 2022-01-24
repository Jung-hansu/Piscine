/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:21:44 by sueshin           #+#    #+#             */
/*   Updated: 2022/01/23 21:55:51 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

t_dict	*g_start = NULL;
t_dict	*g_end = NULL;

char	*get_num(int fd)
{
	int		i;
	char	c[1];
	char	*str;

	str = malloc(sizeof(char) * 1024);
	if (!str)
		return (0);
	i = 0;
	read(fd, c, 1);
	while (c[0] == '\n')
		read(fd, c, 1);
	while (c[0] >= '0' && c[0] <= '9')
	{
		str[i] = c[0];
		read(fd, c, 1);
		i++;
	}
	return (str);
}

char	*get_mean(int fd, char *c)
{
	int		i;
	char	*str;

	str = malloc(sizeof(char) * 1024);
	if (!str)
		return (0);
	i = 0;
	while (c[0] != '\n')
	{
		str[i] = c[0];
		read(fd, c, 1);
		i++;
	}
	return (str);
}

int	fd_size(char *filename)
{
	int		fd;
	int		count;
	char	c[1];

	count = 0;
	fd = open(filename, O_RDWR, 0777);
	if (fd < 0)
		return (-1);
	while (read(fd, c, 1) > 0)
	{
		if (c[0] == '\n')
			count++;
	}
	close(fd);
	return (count);
}

int	mk_file_node(char *str)
{
	int		fd;
	char	*num;
	char	c[1];
	int		i;
	int		indexsize;

	i = -1;
	indexsize = fd_size(str);
	fd = open(str, O_RDWR, 0777);
	if (fd < 0)
		return (0);
	while (i++ < indexsize)
	{
		num = get_num(fd);
		read(fd, c, 1);
		while (c[0] == ' ')
			read(fd, c, 1);
		if (c[0] == ':')
			read(fd, c, 1);
		while (c[0] == ' ')
			read(fd, c, 1);
		add_node(num, get_mean(fd, c));
	}
	close(fd);
	return (1);
}

int	main(int ac, char **av)
{
	int	flag;
	int	idx;

	flag = 0;
	idx = -1;
	if (ac == 2)
	{
		mk_file_node("numbers.dict");
		extract_num(str_check(av[1]), flag, idx);
		return (0);
	}
	else if (ac == 3)
	{
		mk_file_node(av[1]);
		extract_num(str_check(av[2]), flag, idx);
	}
}
