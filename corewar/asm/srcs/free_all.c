/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:32:20 by xgilbert          #+#    #+#             */
/*   Updated: 2019/04/09 19:45:39 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			free_instr(t_asm *tasm)
{
	int			n;
	int			a;

	n = 0;
	ft_printf("ici xavier\n");
	if (tasm->instr)
	{

	ft_printf("ok\n");
		while (tasm->instr[n])
		{

	ft_printf("ok0\n");
			a = 0;
			tasm->instr[n]->label ? free(tasm->instr[n]->label) : 0;
	ft_printf("ok0\n");
			tasm->instr[n]->name ? free(tasm->instr[n]->name) : 0;
	ft_printf("ok0\n");
			tasm->instr[n]->code_hexa ? free(tasm->instr[n]->code_hexa) : 0;
	ft_printf("ok0\n");
			while (a < 3)
			{
				tasm->instr[n]->args[a] ? free(tasm->instr[n]->args[a]) : 0;
				a++;
			}
	ft_printf("ok1\n");
			free(tasm->instr[n]);
	ft_printf("ok2\n");
			n++;
		}
		ft_printf("ici lucas\n");
		free(tasm->instr);
	}
}

void			free_file(t_asm *tasm)
{
	int			i;

	i = 0;
	if (tasm->file)
	{
		while (tasm->file[i])
			free(tasm->file[i++]);
		free(tasm->file);
	}
}

void			free_all(t_asm *tasm)
{
	ft_printf("ok\n");
	free_instr(tasm);
	ft_printf("ok\n");
	tasm->header ? free(tasm->header) : 0;
	ft_printf("ok\n");
	free_file(tasm);
}

void			free_and_exit(t_asm *tasm)
{
	free_all(tasm);
	exit(0);
}
