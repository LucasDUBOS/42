/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:22:41 by lucdubos          #+#    #+#             */
/*   Updated: 2018/10/24 15:22:50 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_nbr_max_min_b(int **tab, int *nbrb, int *min)
{
	int i;
	int max;

	i = 1;
	max = tab[1][0];
	*min = tab[1][0];
	while (i < *nbrb)
	{
		if (max < tab[1][i])
			max = tab[1][i];
		if (*min > tab[1][i])
			*min = tab[1][i];
		i++;
	}
	return (max);
}

int			ft_where_is_min(int **tab, int min)
{
	int i;

	i = 0;
	while (tab[1][i] != min)
	{
		i++;
	}
	return (i + 1);
}

int			ft_where_is_max(int **tab, int max)
{
	int i;

	i = 0;
	while (tab[1][i] != max)
	{
		i++;
	}
	return (i + 1);
}

void		ft_second_max_min(t_struct *s, int min, int max)
{
	int i;

	s->second_min = max;
	s->second_max = min;
	i = 0;
	if (s->nbrb >= 4)
	{
		while (i < s->nbrb)
		{
			if (s->second_max < s->tab[1][i] && s->tab[1][i] < max)
				s->second_max = s->tab[1][i];
			if (s->second_min > s->tab[1][i] && s->tab[1][i] > min)
				s->second_min = s->tab[1][i];
			i++;
		}
	}
}
