/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:45:40 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/17 20:39:45 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	int i;
	int stock;

	i = 0;
	if (n == 0)
		return (0);
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	while (s1[i] == s2[i] && n > 1)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
		n--;
	}
	stock = ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (stock);
}
