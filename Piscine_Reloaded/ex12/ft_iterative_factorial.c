/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:29:52 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/06 16:41:19 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int count;
	int res;

	count = 1;
	res = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (count <= nb)
	{
		res = res * count;
		count++;
	}
	return (res);
}
