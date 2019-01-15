/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:06:31 by lucdubos          #+#    #+#             */
/*   Updated: 2018/09/18 13:18:58 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_start(int *i, int *neg, intmax_t base, intmax_t value)
{
	intmax_t	stock;

	stock = value;
	if (value < 0 && base == 10)
	{
		*neg = 1;
		value *= -1;
	}
	if (value < 0 && base != 10)
		value *= -1;
	stock = value;
	while (stock >= 1)
	{
		stock /= base;
		*i = *i + 1;
	}
	*i = *i + *neg;
}

char	*ft_itoa_base(intmax_t value, intmax_t base)
{
	int		i;
	char	*str;
	int		neg;

	i = 0;
	neg = 0;
	ft_start(&i, &neg, base, value);
	if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	if (neg == 1)
		str[0] = '-';
	i--;
	while (i >= neg)
	{
		if (value % base > 9)
			str[i] = value % base + 'A' - 10;
		else
			str[i] = value % base + '0';
		value /= base;
		i--;
	}
	return (str);
}
