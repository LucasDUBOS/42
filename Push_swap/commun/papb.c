/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   papb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:34:57 by lucdubos          #+#    #+#             */
/*   Updated: 2018/10/24 15:22:28 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		pa_end(t_struct *s)
{
	if (s->ecriture == 0)
	{
		ft_putstr("pa\n");
		if (s->options == 1)
			sleep(1);
	}
	s->nbr_coup++;
	if (s->optionv == 1 && s->ecriture == 0)
		printtab(s);
}

void		pa(t_struct *s)
{
	int i;
	int tmp;

	if (s->nbrb >= 1)
	{
		i = s->nbra;
		tmp = s->tab[0][0];
		while (i > 0)
		{
			s->tab[0][i] = s->tab[0][i - 1];
			i--;
		}
		s->tab[0][0] = s->tab[1][0];
		s->nbra = s->nbra + 1;
		i = -1;
		s->nbrb = s->nbrb - 1;
		while (i++ < s->nbrb)
			s->tab[1][i] = s->tab[1][i + 1];
	}
	pa_end(s);
}

void		pb(t_struct *s)
{
	int i;
	int tmp;

	if (s->nbra >= 1)
	{
		i = s->nbrb;
		tmp = s->tab[1][0];
		while (i > 0)
		{
			s->tab[1][i] = s->tab[1][i - 1];
			i--;
		}
		s->tab[1][0] = s->tab[0][0];
		s->nbrb = s->nbrb + 1;
		i = -1;
		s->nbra = s->nbra - 1;
		while (i++ < s->nbra)
			s->tab[0][i] = s->tab[0][i + 1];
	}
	if (s->ecriture == 0)
		ft_putstr("pb\n");
	if (s->optionv == 1 && s->ecriture == 0)
		printtab(s);
	s->nbr_coup++;
}
