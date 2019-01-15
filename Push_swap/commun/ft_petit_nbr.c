/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_petit_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:17:25 by lucdubos          #+#    #+#             */
/*   Updated: 2018/10/24 15:21:01 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_nbr_min_a(t_struct *s)
{
	int min;
	int i;

	i = 0;
	min = s->tab[0][0];
	while (i < s->nbra)
	{
		if (min > s->tab[0][i])
			min = s->tab[0][i];
		i++;
	}
	return (min);
}

void	ft_petit_nbr4_1(t_struct *s, int min)
{
	if (s->tab[0][3] == min)
	{
		rra(s);
		rra(s);
		pb(s);
	}
	else
	{
		rra(s);
		pb(s);
	}
}

void	ft_petit_nbr4(t_struct *s)
{
	int min;

	min = ft_nbr_min_a(s);
	if (s->tab[0][0] == min)
		pb(s);
	else if (s->tab[0][1] == min)
	{
		ra(s);
		pb(s);
	}
	else if (s->tab[0][2] == min)
	{
		ra(s);
		ra(s);
		pb(s);
	}
	else if (s->nbra == 5)
		ft_petit_nbr4_1(s, min);
	else
	{
		rra(s);
		pb(s);
	}
}

void	ft_petit_nbr5(t_struct *s)
{
	ft_petit_nbr4(s);
	ft_petit_nbr4(s);
	s->nbrb = 0;
	ft_petit_nbr3(s);
	s->nbrb = 2;
	pa(s);
	pa(s);
}

void	ft_petit_nbr(t_struct *s, int argc, char **argv)
{
	if (argc <= 4)
		ft_petit_nbr3(s);
	if (argc == 5)
	{
		ft_petit_nbr4(s);
		s->nbrb = 0;
		ft_petit_nbr3(s);
		s->nbrb = 1;
		pa(s);
	}
	if (argc == 6)
		ft_petit_nbr5(s);
	if (argc == 7)
		ft_petit_nbr6(s, argv);
}
