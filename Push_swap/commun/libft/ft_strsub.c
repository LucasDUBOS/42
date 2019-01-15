/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:06:23 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/20 19:55:24 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;

	if (s != NULL)
	{
		i = len;
		ptr = (char*)malloc(sizeof(*ptr) * (len + 1));
		if (ptr == NULL)
			return (NULL);
		len = 0;
		while (i > 0)
		{
			ptr[len] = s[start];
			len++;
			start++;
			i--;
		}
		ptr[len] = '\0';
		return (ptr);
	}
	return (0);
}
