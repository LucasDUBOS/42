/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrarrbrrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:31:44 by lucdubos          #+#    #+#             */
/*   Updated: 2018/10/24 15:26:09 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rra(t_struct *s)
{
	int tmp;
	int i;

	if (s->nbra > 1)
	{
		i = s->nbra - 1;
		tmp = s->tab[0][i];
		while (0 < i)
		{
			s->tab[0][i] = s->tab[0][i - 1];
			i--;
		}
		s->tab[0][0] = tmp;
	}
	if (s->ecriture == 0)
		ft_putstr("rra\n");
	s->nbr_coup++;
	if (s->optionv == 1 && s->ecriture == 0)
		printtab(s);
}

void		rrb(t_struct *s)
{
	int tmp;
	int i;

	if (s->nbrb > 1)
	{
		i = s->nbrb - 1;
		tmp = s->tab[1][i];
		while (0 < i)
		{
			s->tab[1][i] = s->tab[1][i - 1];
			i--;
		}
		s->tab[1][0] = tmp;
	}
	if (s->ecriture == 0)
		ft_putstr("rrb\n");
	s->nbr_coup++;
	if (s->optionv == 1 && s->ecriture == 0)
		printtab(s);
}

void		rrr(t_struct *s)
{
	if (s->ecriture == 0)
	{
		s->ecriture = 1;
		rra(s);
		rrb(s);
		s->ecriture = 0;
		ft_putstr("rrr\n");
	}
	else
	{
		rra(s);
		rrb(s);
	}
	s->nbr_coup++;
	if (s->optionv == 1 && s->ecriture == 0)
		printtab(s);
}
