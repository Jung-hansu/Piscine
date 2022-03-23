/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanjung <hanjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:39:56 by hanjung           #+#    #+#             */
/*   Updated: 2022/03/23 21:47:55 by hanjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = s + ft_strlen(s) - 1;
	while (*tmp != (char)c)
	{
		if (tmp < s)
			return (0);
		tmp--;
	}
	return (tmp);
}
