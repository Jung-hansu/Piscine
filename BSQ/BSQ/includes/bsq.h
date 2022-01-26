/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woojlee <woojlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:06:06 by woojlee           #+#    #+#             */
/*   Updated: 2022/01/25 21:06:09 by woojlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define ERR_MSG "map error\n"

typedef struct t_square
{
	int		x;
	int		y;
	int		len;
}	t_square;

typedef struct t_map
{
	char	full;
	char	empty;
	char	obstacle;
	int		x_len;
	int		y_len;
	char	**arr;
}	t_map;

t_map		*read_file(char *file);
t_map		*read_stdin(void);
t_map		*read_map(int fd, t_map *map, int *size, int cnt);
t_square	*find_bsq(t_map *map);
void		find_bsq_sub(int i, t_map *map, int **arr, t_square *square);

int			**make_arr(t_map *map);
void		change_square(t_square *square, int x, int y, int len);
void		modify_map(t_map *map, t_square *square);
void		print(t_map *map, t_square *square);
void		free_map(t_map *map, int size);
int			parse_map_info_sub(t_map *map, char *info);
int			read_map_sub(int *idx, t_map *map, char *line);
int			parse_map_info(t_map *map, char *info);

char		*expand_size(char *src, int *size);
char		*free_line(char *line);
int			ft_check_square(int **arr, int i, int j);

int			ft_atoi(char *str);
void		ft_strncpy(char *dst, char *src, int size);
int			ft_strlen(char *str);
void		ft_putstr(char *str);
void		ft_put_errmsg(char *str);
int			ft_min(int a, int b, int c);
int			is_printable(char c);
int			is_dupl(char a, char b, char c);

int			is_valid_map_info(t_map *map);
int			ft_is_valid_map(char *line, t_map *map);

#endif