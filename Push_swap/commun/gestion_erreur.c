/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_erreur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:59:54 by lucdubos          #+#    #+#             */
/*   Updated: 2018/10/24 15:22:02 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_gestion_erreur2(char **tab, int i, char **tmp, t_struct *s)
{
	int tmp1;

	tmp1 = s->j_err;
	while (s->j_err < s->nbb)
	{
		if (ft_strcmp(tab[i], tab[s->j_err]) == 0)
		{
			free(*tmp);
			return (0);
		}
		s->j_err++;
	}
	s->j_err = tmp1;
	return (1);
}

int		gestion_erreur(char **tab, int argc, t_struct *s)
{
	int		i;
	char	*tmp;

	s->nbb = argc;
	i = 1;
	s->j_err = 2;
	while (tab[i])
	{
		tmp = ft_itoa(ft_atoi(tab[i]));
		if (i < argc && ft_strcmp(tmp, tab[i]) != 0)
		{
			free(tmp);
			return (0);
		}
		if (ft_gestion_erreur2(tab, i, &tmp, s) == 0)
			return (0);
		i++;
		s->j_err = i + 1;
		free(tmp);
	}
	return (1);
}
