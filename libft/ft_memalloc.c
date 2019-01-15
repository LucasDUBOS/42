/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:26:15 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/15 16:02:30 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *mal;

	mal = (void*)malloc(size);
	if (mal == NULL)
		return (NULL);
	ft_bzero(mal, size);
	return (mal);
}
