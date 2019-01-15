/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:14:18 by lucdubos          #+#    #+#             */
/*   Updated: 2018/10/24 17:14:20 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commun/push_swap.h"

void		last_mediane(t_struct *s)
{
	int i;

	i = 0;
	while (s->tab[0][0] != s->min)
	{
		pb(s);
	}
	while (s->nbrb > 0)
	{
		push_b_max(s);
	}
	while (s->tab[0][0] != s->min)
	{
		ra(s);
	}
}

int			ft_algo(t_struct *s)
{
	int i;

	i = 0;
	ft_push_b_mediane(s);
	s->sens_rot_a_apres_full_pa = 0;
	while (s->nbrb > 0)
	{
		push_b_max(s);
	}
	ft_rot_a_sens(s);
	if (s->sens_rot_a_apres_full_pa == 1 || s->last_med == 1)
	{
		while (s->tab[0][0] <= s->mediane)
		{
			ra(s);
		}
	}
	else
		while (s->tab[0][0] != s->min)
		{
			rra(s);
		}
	return (1);
}

void		ft_algo1(t_struct *s, int **tab2)
{
	int i;

	i = 0;
	while (i < s->nbr_mediane)
	{
		if (is_tri(s->tab, &s->nbra, &s->nbrb))
		{
			exit(0);
		}
		if (s->mediane_passee >= 1)
			s->med_av = s->mediane;
		s->mediane = ft_mediane(tab2[0], s->nbra, s);
		if (i + 1 == s->nbr_mediane)
			s->last_med = 1;
		ft_algo(s);
		s->mediane_passee++;
		i++;
	}
	last_mediane(s);
	s->last_med = 0;
}
