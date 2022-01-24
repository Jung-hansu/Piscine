/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:03:05 by sueshin           #+#    #+#             */
/*   Updated: 2022/01/23 22:03:08 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H
# define FT_H_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*ft_set_bignum(int count);
void	ft_find_dict0(int num);
void	ft_find_dict1(int num, int flag);
void	ft_find_dict2(char *str);
void	ft_putstr(char *str);
int		ft_power(int nb, int power);
void	ft_print_hundred(int nbr, int count, int flag);
void	ft_putchar(char c);
void	extract_num(char *num, int flag, int idx);
int		str_len(char *str);
char	*str_check(char *str);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
int		mk_file_node(char *str);
void	add_node(char *nbr, char *str);

typedef struct s_dict
{
	char			*num;
	char			*mean;
	struct s_dict	*next;
}	t_dict;

#endif
