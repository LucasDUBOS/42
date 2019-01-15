/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:43:10 by lucdubos          #+#    #+#             */
/*   Updated: 2018/01/16 17:14:40 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ptr;

	ptr = (unsigned char*)s;
	while (n > 0)
	{
		if (*ptr == (unsigned char)c)
			return ((void*)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
