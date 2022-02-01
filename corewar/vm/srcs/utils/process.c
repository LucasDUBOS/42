/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 08:46:32 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/11 12:32:04 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				cpy_process(t_process **dst, t_process *src)
{
	if (!src || !(*dst))
		return (EXIT_FAILURE);
	ft_memcpy((void*)*dst, (const void*)src, sizeof(t_process));
	if (!((*dst)->reg = malloc(sizeof(int) * 16)))
	{
		ft_memdel((void**)dst);
		return (EXIT_FAILURE);
	}
	ft_bzero((*dst)->reg, (16 * sizeof(int)));
	return (EXIT_SUCCESS);
}

void			link_process(t_vm *vm, t_process *new_process)
{
	new_process->next = vm->process_list;
	vm->process_list = new_process;
}

t_process		*new_process(void)
{
	t_process	*new;

	if (!(new = malloc(sizeof(t_process))))
		return (NULL);
	if (!(new->reg = malloc(sizeof(int) * 16)))
	{
		ft_memdel((void**)&new);
		return (NULL);
	}
	ft_bzero(new->reg, (16 * sizeof(int)));
	new->pc = 0;
	new->carry = 0;
	new->op_code = -1;
	new->cycles_to_exec = 0;
	new->live = 0;
	new->id = 0;
	new->next = NULL;
	return (new);
}

static int		init_process(t_vm *vm, t_process *process, int i)
{
	if ((i < 0) || (i >= MAX_PLAYERS))
		return (EXIT_FAILURE);
	process->pc = (MEM_SIZE / vm->nb_champs * i);
	process->carry = 0;
	process->op_code = vm->arena[process->pc];
	process->cycles_to_exec = g_op_tab[vm->arena[process->pc]].cycles - 1;
	process->reg[0] = vm->champs[i].id;
	process->live = 1;
	process->id = ++(vm->nb_process);
	return (EXIT_SUCCESS);
}

int				create_champ_process(t_vm *vm, int champ_pos)
{
	t_process	*new;

	new = NULL;
	if (vm->process_list == NULL)
	{
		if (!(vm->process_list = new_process()))
			return (EXIT_FAILURE);
		init_process(vm, vm->process_list, champ_pos);
	}
	else
	{
		if (!(new = new_process()))
			return (EXIT_FAILURE);
		init_process(vm, new, champ_pos);
		link_process(vm, new);
	}
	return (EXIT_SUCCESS);
}
