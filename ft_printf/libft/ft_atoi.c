/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:59:27 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/15 16:01:56 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int stock;
	int i;
	int neg;

	neg = 1;
	i = 0;
	stock = 0;
	while ((str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\f'
			|| str[i] == ' ') && str[i] != '\b')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		stock = stock * 10 + (str[i] - 48);
		i++;
	}
	stock = stock * neg;
	return (stock);
}
