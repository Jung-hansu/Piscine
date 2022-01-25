/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsong <tsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:27:35 by gicho             #+#    #+#             */
/*   Updated: 2022/01/24 13:58:30 by tsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_square{
	int		x;
	int		y;
	int		len;
}				t_square;

typedef struct	s_map{
	char	full;
	char	empty;
	char	obstacle;
	int		x_len;
	int		y_len;
	char	**arr;
}				t_map;
#endif