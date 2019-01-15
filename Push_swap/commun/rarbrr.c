/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rarbrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:57:29 by lucdubos          #+#    #+#             */
/*   Updated: 2018/10/24 15:24:46 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ra(t_struct *s)
{
	int tmp;
	int i;

	if (s->nbra > 1)
	{
		i = 0;
		tmp = s->tab[0][0];
		while (i < s->nbra)
		{
			s->tab[0][i] = s->tab[0][i + 1];
			i++;
		}
		s->tab[0][s->nbra - 1] = tmp;
	}
	if (s->ecriture == 0)
		ft_putstr("ra\n");
	s->nbr_coup++;
	if (s->optionv == 1 && s->ecriture == 0)
		printtab(s);
}

void		rb(t_struct *s)
{
	int tmp;
	int i;

	if (s->nbrb > 1)
	{
		i = 0;
		tmp = s->tab[1][0];
		while (i < s->nbrb)
		{
			s->tab[1][i] = s->tab[1][i + 1];
			i++;
		}
		s->tab[1][s->nbrb - 1] = tmp;
	}
	if (s->ecriture == 0)
		ft_putstr("rb\n");
	s->nbr_coup++;
	if (s->optionv == 1 && s->ecriture == 0)
		printtab(s);
}

void		rr(t_struct *s)
{
	if (s->ecriture == 0)
	{
		s->ecriture = 1;
		ra(s);
		rb(s);
		ft_putstr("rr\n");
		s->ecriture = 0;
	}
	else
	{
		ra(s);
		rb(s);
	}
	s->nbr_coup++;
	if (s->optionv == 1 && s->ecriture == 0)
		printtab(s);
}
