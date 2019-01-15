/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_mediane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:33:46 by lucdubos          #+#    #+#             */
/*   Updated: 2018/10/24 15:33:54 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_tri(int **tab, int *nbra, int *nbrb)
{
	int i;

	i = 0;
	if (*nbrb != 0)
		return (0);
	while (i < *nbra - 1)
	{
		if (tab[0][i] >= tab[0][i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		ft_mediane(int *tab, int nb, t_struct *s)
{
	int ret;

	ft_sort_integer_table(tab, nb);
	s->min = tab[0];
	ret = (nb / (s->nbr_mediane + 1)) * (s->mediane_passee + 1);
	s->mediane_actuelle = tab[ret];
	return (s->mediane_actuelle);
}

int		ft_push_b_mediane(t_struct *s)
{
	if (s->mediane_passee >= 1)
		ft_rot_a_sens(s);
	if (s->sens_rot_a_apres_full_pa == 1)
		ft_rot_rra_sens(s);
	else
		ft_rot_ra_sens(s);
	return (1);
}
