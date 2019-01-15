/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_petit_nbr6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 12:25:44 by lucdubos          #+#    #+#             */
/*   Updated: 2018/10/24 15:21:19 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_petit_nbr3(t_struct *s)
{
	while (!(is_tri(s->tab, &s->nbra, &s->nbrb)))
	{
		if (s->tab[0][1] < s->tab[0][0])
			sa(s);
		else
		{
			if (s->tab[0][1] > s->tab[0][s->nbra - 1])
				rra(s);
			else
				ra(s);
		}
	}
}

void		ft_petit_nbr6_3(t_struct *s, int tri_b)
{
	while (tri_b != 1)
	{
		if (s->tab[1][1] > s->tab[1][0])
			sb(s);
		else
		{
			if (s->tab[1][1] < s->tab[1][2])
				rrb(s);
			else
				rb(s);
		}
		if (s->tab[1][0] > s->tab[1][1] && s->tab[1][1] > s->tab[1][2])
			tri_b = 1;
	}
}

void		ft_petit_nbr6_2(t_struct *s)
{
	if (s->tab[0][1] > s->tab[0][s->nbra - 1])
	{
		if (s->tab[1][1] < s->tab[1][s->nbrb - 1])
			rrr(s);
		else
			rra(s);
	}
	else
	{
		if (s->tab[1][1] > s->tab[1][s->nbra - 1])
			rr(s);
		else
			ra(s);
	}
}

void		ft_petit_nbr6_1(t_struct *s)
{
	int tri_a;
	int tri_b;

	tri_a = 0;
	tri_b = 0;
	while (tri_a != 1)
	{
		if (s->tab[0][1] < s->tab[0][0])
		{
			if (s->tab[1][1] > s->tab[1][0])
				ss(s);
			else
				sa(s);
		}
		else
			ft_petit_nbr6_2(s);
		if (s->tab[0][0] < s->tab[0][1] && s->tab[0][1] < s->tab[0][2])
			tri_a = 1;
		if (s->tab[1][0] > s->tab[1][1] && s->tab[1][1] > s->tab[1][2])
			tri_b = 1;
	}
	if (tri_b != 1)
		ft_petit_nbr6_3(s, tri_b);
}

void		ft_petit_nbr6(t_struct *s, char **argv)
{
	int i;
	int **tab2;

	i = 0;
	s->nbr_mediane = 1;
	tab2 = stock_int_ps(argv, s->nbra);
	ft_mediane(tab2[0], 6, s);
	free(tab2[1]);
	free(tab2[0]);
	free(tab2);
	while (s->nbrb < 3)
	{
		if (s->tab[0][0] < s->mediane_actuelle)
			pb(s);
		else
			ra(s);
		i++;
	}
	ft_petit_nbr6_1(s);
	pa(s);
	pa(s);
	pa(s);
}
