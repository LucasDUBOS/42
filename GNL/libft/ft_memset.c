/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:46:45 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/13 17:51:35 by lucdubos         ###   ########.fr       */
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
