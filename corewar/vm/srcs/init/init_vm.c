/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:01:11 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/11 12:27:48 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	init_champs(t_champ *champs)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		champs[i].id = -1;
		ft_bzero(&(champs[i].data), sizeof(t_champ_data));
		champs[i].filepath = NULL;
		champs[i].last_cycle_alive = -1;
		i++;
	}
	return (EXIT_SUCCESS);
}

int			init_vm(t_vm *vm)
{
	if (!(vm->arena = malloc(sizeof(t_mem) * MEM_SIZE)))
		return (EXIT_FAILURE);
	ft_bzero(vm->arena, MEM_SIZE);
	if (!(vm->champs = malloc(sizeof(t_champ) * MAX_PLAYERS)))
		return (EXIT_FAILURE);
	if (init_champs(vm->champs) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	vm->process_list = NULL;
	vm->dump_nb = -1;
	vm->last_champ_alive = -1;
	vm->nb_champs = -1;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->nb_live = 0;
	vm->nb_process = 0;
	vm->debug = 0;
	return (EXIT_SUCCESS);
}
