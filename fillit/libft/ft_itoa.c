/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:05:29 by xgilbert          #+#    #+#             */
/*   Updated: 2017/11/20 20:01:08 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_end(int sign, int len, int stock, int n)
{
	char	*str;

	while (stock >= 10)
	{
		stock /= 10;
		len++;
	}
	if (!((str = (char*)malloc(sizeof(char) * len))))
		return (NULL);
	str[len] = '\0';
	while (len-- >= 0)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}

char			*ft_itoa(int n)
{
	int		stock;
	int		len;
	char	*str;
	int		sign;

	len = 1;
	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = 1;
		n = -n;
		len++;
	}
	stock = n;
	str = ft_end(sign, len, stock, n);
	return (str);
}
