/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:30:05 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/20 19:47:55 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t i2;

	i = 0;
	i2 = 0;
	if (to_find[i] == '\0')
		return ((char*)str);
	while (str[i] != '\0' && i < len)
	{
		while (str[i] == to_find[i2] && i < len)
		{
			i++;
			i2++;
			if (to_find[i2] == '\0')
				return ((char*)(str + i - i2));
		}
		i = i - i2;
		i2 = 0;
		i++;
	}
	return (NULL);
}
