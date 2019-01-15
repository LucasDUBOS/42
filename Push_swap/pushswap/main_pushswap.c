/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:07:35 by lucdubos          #+#    #+#             */
/*   Updated: 2018/10/24 14:48:28 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commun/push_swap.h"

int		main(int argc, char **argv)
{
	t_struct	s;

	s.mediane_passee = 0;
	s.optionv = 0;
	s.options = 0;
	s.sens_rot_a_apres_full_pa = 0;
	if (error_optionv(argv, &argc, &s) == 0)
		return (0);
	s.nbra = argc - 1;
	s.nbrb = 0;
	if (argc <= 7)
	{
		s.ecriture = 0;
		s.tab = stock_int_ps(argv, s.nbra);
		if (s.optionv == 1)
			printtab(&s);
		if (!(is_tri(s.tab, &s.nbra, &s.nbrb)))
			ft_petit_nbr(&s, argc, argv);
		free(s.tab[1]);
		free(s.tab[0]);
		free(s.tab);
		return (0);
	}
	ft_algo3(&s, argc, argv);
	return (0);
}
