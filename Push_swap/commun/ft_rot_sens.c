/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot_sens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:21:42 by lucdubos          #+#    #+#             */
/*   Updated: 2018/10/24 15:21:48 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rot_a_sens(t_struct *s)
{
	int placement;
	int i;

	i = 0;
	placement = 0;
	while (s->tab[0][i] != s->min)
		i++;
	if (i < s->nbra / 2)
		s->sens_rot_a_apres_full_pa = 1;
	else
		s->sens_rot_a_apres_full_pa = 0;
}

void	ft_rot_rra_sens(t_struct *s)
{
	while (s->tab[0][s->nbra - 1] != s->med_av)
	{
		if ((s->tab[0][0] <= s->mediane) && (s->tab[0][0] > s->med_av))
		{
			pb(s);
		}
		else
		{
			rra(s);
		}
	}
	if ((s->tab[0][0] <= s->mediane) && (s->tab[0][0] > s->med_av))
	{
		pb(s);
	}
}

void	ft_rot_ra_sens(t_struct *s)
{
	int i;

	i = s->nbra;
	if (s->mediane_passee >= 1)
	{
		while (i > 0)
		{
			if ((s->tab[0][0] <= s->mediane) && (s->tab[0][0] > s->med_av))
				pb(s);
			else
				ra(s);
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			if (s->tab[0][0] <= s->mediane)
				pb(s);
			else
				ra(s);
			i--;
		}
	}
}
