/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:46:45 by lucdubos          #+#    #+#             */
/*   Updated: 2018/01/16 16:52:20 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned int	i;
	char			*ptr;

	ptr = s;
	i = 0;
	while (i < len)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}
