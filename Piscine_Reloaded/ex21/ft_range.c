/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:55:10 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/07 17:30:33 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *str;
	int i;
	int j;

	i = 0;
	j = min;
	if (min >= max)
		return (NULL);
	while (j < max)
	{
		i++;
		j++;
	}
	str = (int*)malloc(sizeof(*str) * i);
	i = 0;
	while (min < max)
	{
		str[i] = min;
		i++;
		min++;
	}
	return (str);
}
