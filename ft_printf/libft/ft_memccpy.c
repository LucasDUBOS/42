/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:41:43 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/15 16:02:45 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n > 0)
	{
		*(unsigned char*)dest = *(unsigned char*)src;
		if (*(unsigned char*)src == (unsigned char)c)
		{
			dest++;
			return (dest);
		}
		dest++;
		src++;
		n--;
	}
	return (NULL);
}
