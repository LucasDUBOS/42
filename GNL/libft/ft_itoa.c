/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:54:04 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/20 19:02:09 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_end(int flag, int len, int stock, int n)
{
	char *str;

	while (stock >= 10)
	{
		stock = stock / 10;
		len++;
	}
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	len--;
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	if (flag > 0)
		str[0] = '-';
	return (str);
}

char			*ft_itoa(int n)
{
	int		stock;
	int		len;
	char	*str;
	int		flag;

	len = 2;
	flag = 0;
	if (n > 2147483647 || n < -2147483648)
		return (0);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		flag++;
		n = -n;
		len++;
	}
	stock = n;
	str = ft_end(flag, len, stock, n);
	return (str);
}
