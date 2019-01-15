/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:24:25 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/13 18:46:39 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	unsigned char		*ptr2;
	unsigned long		i;
	void				*ptrv;

	i = 0;
	ptrv = (void*)src;
	ptr = dest;
	ptr2 = ptrv;
	while (i < n)
	{
		ptr[i] = ptr2[i];
		i++;
	}
	return (dest);
}
