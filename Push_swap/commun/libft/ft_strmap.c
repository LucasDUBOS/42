/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:52:40 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/23 17:57:27 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	int		i;

	if (s != NULL)
	{
		i = 0;
		ptr = (char *)malloc(sizeof(*ptr) * (ft_strlen((char*)s) + 1));
		if (ptr == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			ptr[i] = f(s[i]);
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	return (0);
}
