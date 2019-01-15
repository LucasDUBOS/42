/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depil_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:16:57 by lucdubos          #+#    #+#             */
/*   Updated: 2018/10/24 15:20:28 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_2(t_struct *s)
{
	while (s->tab[1][0] != s->max)
	{
		ft_depil_rb_max(s);
	}
	pa(s);
	if (s->flag_depil == 1)
	{
		sa(s);
		s->flag_depil = 0;
	}
}

void	push_b_3(t_struct *s, int min)
{
	while (s->tab[1][0] != min)
	{
		ft_depil_rb_min(s);
	}
	pa(s);
	if (s->flag_depil == 1)
	{
		ra(s);
		s->flag_depil = 0;
	}
}

void	push_b_4(t_struct *s, int min)
{
	while (s->tab[1][0] != min)
	{
		ft_depil_rrb_min(s);
	}
	pa(s);
	if (s->flag_depil == 1)
	{
		ra(s);
		s->flag_depil = 0;
	}
}

void	push_b_max2(t_struct *s, int min, int placement, int placement_min)
{
	if (((s->nbrb - placement + 1) <= (s->nbrb - placement_min + 1)) &&
			((s->nbrb - placement + 1) <= placement) &&
			((s->nbrb - placement + 1) <= placement_min))
	{
		push_b_1(s);
	}
	else if ((placement <= placement_min) &&
			(placement <= (s->nbrb - placement_min + 1)))
	{
		push_b_2(s);
	}
	else if (placement_min <= (s->nbrb - placement_min + 1))
	{
		push_b_3(s, min);
		ra(s);
	}
	else
	{
		push_b_4(s, min);
		ra(s);
	}
}

void	push_b_max(t_struct *s)
{
	int placement;
	int placement_min;
	int min;

	s->second_min = 0;
	s->second_max = 0;
	s->max = ft_nbr_max_min_b(s->tab, &s->nbrb, &min);
	ft_second_max_min(s, min, s->max);
	placement = ft_where_is_max(s->tab, s->max);
	placement_min = ft_where_is_min(s->tab, min);
	s->flag_depil = 0;
	if (s->nbrb == 3 && s->tab[1][0] > s->tab[1][2]
			&& s->tab[1][0] < s->tab[1][1])
	{
		sb(s);
		pa(s);
		pa(s);
		pa(s);
	}
	else
	{
		push_b_max2(s, min, placement, placement_min);
	}
}
