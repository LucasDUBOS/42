/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:01:59 by lucdubos          #+#    #+#             */
/*   Updated: 2018/10/24 17:16:16 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commun/push_swap.h"

int		ft_instructions(t_struct *s, char *line)
{
	if ((ft_strcmp(line, "sa") == 0))
		sa(s);
	else if ((ft_strcmp(line, "sb") == 0))
		sb(s);
	else if ((ft_strcmp(line, "ss") == 0))
		ss(s);
	else if ((ft_strcmp(line, "ra") == 0))
		ra(s);
	else if ((ft_strcmp(line, "rb") == 0))
		rb(s);
	else if ((ft_strcmp(line, "rr") == 0))
		rr(s);
	else if ((ft_strcmp(line, "rra") == 0))
		rra(s);
	else if ((ft_strcmp(line, "rrb") == 0))
		rrb(s);
	else if ((ft_strcmp(line, "rrr") == 0))
		rrr(s);
	else if ((ft_strcmp(line, "pa") == 0))
		pa(s);
	else if (ft_strcmp(line, "pb") == 0)
		pb(s);
	else
		return (0);
	return (1);
}

int		ft_end(t_struct *s, char *line)
{
	while (get_next_line(0, &line) == 1)
	{
		if (ft_instructions(s, line) == 0)
		{
			write(2, "Error\n", 6);
			free(s->tab[1]);
			free(s->tab[0]);
			free(s->tab);
			free(line);
			return (0);
		}
		free(line);
	}
	if (is_tri(s->tab, &s->nbra, &s->nbrb) && s->nbrb == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free(s->tab[1]);
	free(s->tab[0]);
	free(s->tab);
	return (1);
}

int		main(int argc, char **argv)
{
	t_struct	s;
	char		*line;

	s.nbra = argc - 1;
	s.nbrb = 0;
	s.optionv = 0;
	s.options = 0;
	if (argc == 1)
	{
		return (0);
	}
	if (gestion_erreur(argv, argc, &s) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	s.tab = stock_int_ps(argv, s.nbra);
	s.ecriture = 1;
	ft_end(&s, line);
	return (0);
}
