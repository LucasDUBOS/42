/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:47:02 by lucdubos          #+#    #+#             */
/*   Updated: 2018/09/17 14:48:54 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		taille_malloc(uintmax_t nb, uintmax_t base)
{
	int			i;

	i = 1;
	while (nb >= base)
	{
		i++;
		nb /= base;
	}
	return (i);
}

char			*ft_uitoa_base(uintmax_t nb, uintmax_t base)
{
	char		*str;
	int			p;

	p = taille_malloc(nb, base);
	if (base < 2 || 16 < base
	|| !(str = (char *)malloc(sizeof(char) * p + 2)))
		return (NULL);
	p = 0;
	while (base <= nb)
	{
		if (base > 10 && (nb % base >= 10))
			str[p++] = (nb % base) - 10 + 'a';
		else
			str[p++] = (nb % base) + '0';
		nb /= base;
	}
	if (base > 10 && (nb % base >= 10))
		str[p++] = (nb % base) - 10 + 'a';
	else
		str[p++] = (nb % base) + '0';
	str[p] = '\0';
	return (ft_strrev(str));
}
