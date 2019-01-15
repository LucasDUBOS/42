/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_depil_sens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:17:12 by lucdubos          #+#    #+#             */
/*   Updated: 2018/10/24 15:20:48 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_depil_rrb_max(t_struct *s)
{
	if (s->nbrb >= 4)
	{
		if (s->tab[1][0] == s->second_max)
		{
			pa(s);
			s->flag_depil = 1;
			return (1);
		}
		else
			rrb(s);
	}
	else
		rrb(s);
	return (0);
}

int		ft_depil_rb_max(t_struct *s)
{
	if (s->nbrb >= 4)
	{
		if (s->tab[1][0] == s->second_max)
		{
			pa(s);
			s->flag_depil = 1;
			return (1);
		}
		else
			rb(s);
	}
	else
		rb(s);
	return (0);
}

int		ft_depil_rb_min(t_struct *s)
{
	if (s->nbrb >= 4)
	{
		if (s->tab[1][0] == s->second_min)
		{
			pa(s);
			s->flag_depil = 1;
			return (1);
		}
		else
			rb(s);
	}
	else
		rb(s);
	return (0);
}

int		ft_depil_rrb_min(t_struct *s)
{
	if (s->nbrb >= 4)
	{
		if (s->tab[1][0] == s->second_min)
		{
			pa(s);
			s->flag_depil = 1;
			return (1);
		}
		else
			rrb(s);
	}
	else
		rrb(s);
	return (0);
}
