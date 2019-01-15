/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sasbss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:26:22 by lucdubos          #+#    #+#             */
/*   Updated: 2018/10/24 15:26:51 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sa(t_struct *s)
{
	if (s->nbra >= 2)
	{
		ft_swap(&s->tab[0][0], &s->tab[0][1]);
	}
	if (s->ecriture == 0)
		ft_putstr("sa\n");
	s->nbr_coup++;
	if (s->optionv == 1 && s->ecriture == 0)
		printtab(s);
}

void		sb(t_struct *s)
{
	if (s->nbrb >= 2)
	{
		ft_swap(&s->tab[1][0], &s->tab[1][1]);
	}
	if (s->ecriture == 0)
		ft_putstr("sb\n");
	s->nbr_coup++;
	if (s->optionv == 1 && s->ecriture == 0)
		printtab(s);
}

void		ss(t_struct *s)
{
	if (s->ecriture == 0)
	{
		s->ecriture = 1;
		sa(s);
		sb(s);
		ft_putstr("ss\n");
		s->ecriture = 0;
	}
	else
	{
		sa(s);
		sb(s);
	}
	s->nbr_coup++;
	if (s->optionv == 1 && s->ecriture == 0)
		printtab(s);
}
