/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:44:14 by lucdubos          #+#    #+#             */
/*   Updated: 2018/10/24 15:33:27 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_free(int **tab, int **tab2)
{
	free(tab[1]);
	free(tab[0]);
	free(tab);
	free(tab2[1]);
	free(tab2[0]);
	free(tab2);
}

int			**stock_int_ps(char **str, int n)
{
	int **tab;
	int i;
	int j;

	j = 1;
	i = 0;
	if (!(tab = (int**)malloc(sizeof(int**) * 2)))
		exit(0);
	if (!(tab[0] = (int*)malloc(sizeof(int*) * n)))
		exit(0);
	if (!(tab[1] = (int*)malloc(sizeof(int*) * n)))
		exit(0);
	while (i < n)
	{
		tab[0][i] = ft_atoi(str[j]);
		i++;
		j++;
	}
	return (tab);
}

void		printtab(t_struct *s)
{
	int i;

	i = 0;
	ft_printf("//PILE A----------PILE B-------\\\\\n");
	while (i < s->nbra || i < s->nbrb)
	{
		if (i < s->nbra)
		{
			ft_printf("||%-15d|", s->tab[0][i]);
		}
		else
			ft_printf("||               |");
		if (i < s->nbrb)
		{
			ft_printf("%-13d||\n", s->tab[1][i]);
		}
		else
			ft_printf("             ||\n");
		i++;
	}
	ft_printf(" \\\\---------------------------//\n");
}
