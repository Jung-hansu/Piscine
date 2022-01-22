/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 09:08:40 by hanjung           #+#    #+#             */
/*   Updated: 2022/01/20 09:13:17 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	root;
	int	result;

	root = 0;
	result = 0;
	while (root <= nb && nb >= 0)
	{
		if (root * root == nb)
		{
			result = root;
			break ;
		}
		root++;
	}
	return (result);
}
