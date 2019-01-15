/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:34:56 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/28 19:34:59 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int tmp;
	int i;
	int t;

	i = 0;
	t = 1;
	size--;
	while (i < size)
	{
		if (tab[i] > tab[t])
		{
			tmp = tab[t];
			tab[t] = tab[i];
			tab[i] = tmp;
			i = 0;
			t = 1;
		}
		else
		{
			i++;
			t++;
		}
	}
}
