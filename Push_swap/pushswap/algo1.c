/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:14:31 by lucdubos          #+#    #+#             */
/*   Updated: 2018/10/24 17:14:33 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commun/push_swap.h"

void	optionvs2(char **argv, int *argc, t_struct *s)
{
	if (ft_strcmp(argv[1], "-v") == 0)
	{
		ft_optionv(argv, *argc);
		*argc = *argc - 1;
		s->optionv = 1;
	}
	if (ft_strcmp(argv[1], "-s") == 0)
	{
		ft_optionv(argv, *argc);
		*argc = *argc - 1;
		s->options = 1;
	}
}

int		error_optionv(char **argv, int *argc, t_struct *s)
{
	int i;

	i = 1;
	if (*argc == 1)
		return (0);
	while (i < *argc && i <= 4)
	{
		optionvs2(argv, argc, s);
		i++;
	}
	if (gestion_erreur(argv, *argc, s) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

void	ft_algo2(t_struct *s, int i, char **argv, int ***tab2)
{
	while (s->nbr_coup <= s->nbr_coup2 || i < 2)
	{
		i++;
		s->mediane_passee = 0;
		s->nbr_coup2 = s->nbr_coup;
		s->nbr_coup = 0;
		*tab2 = stock_int_ps(argv, s->nbra);
		s->tab = stock_int_ps(argv, s->nbra);
		if (s->nbr_coup == 0 && s->nbr_coup2 == 0 && s->optionv == 1)
			printtab(s);
		ft_algo1(s, *tab2);
		s->nbr_mediane++;
		s->sens_rot_a_apres_full_pa = 0;
		ft_free(s->tab, *tab2);
	}
	s->nbr_mediane = s->nbr_mediane - 2;
}

void	ft_algo3(t_struct *s, int argc, char **argv)
{
	int i;
	int **tab2;

	i = 0;
	s->nbr_mediane = 1;
	if (argc < 20)
		i++;
	s->nbr_coup = 0;
	s->nbr_coup2 = 0;
	s->ecriture = 1;
	if (argc > 50)
		ft_algo2(s, i, argv, &tab2);
	s->mediane_passee = 0;
	tab2 = stock_int_ps(argv, s->nbra);
	s->tab = stock_int_ps(argv, s->nbra);
	s->ecriture = 0;
	ft_algo1(s, tab2);
	ft_free(s->tab, tab2);
}
