/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:00:22 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/20 20:03:28 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	i;

	if (s != NULL)
	{
		i = 0;
		ptr = (char *)malloc(sizeof(*ptr) * (ft_strlen(s) + 1));
		if (ptr == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			ptr[i] = f(i, s[i]);
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	return (0);
}
