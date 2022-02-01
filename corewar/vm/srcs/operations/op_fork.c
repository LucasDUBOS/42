/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:53:21 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/11 12:33:40 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "instruction.h"

int					op_fork(t_vm *vm, t_process *proc, char *op)
{
	t_instruction	instruction;
	t_process		*new;
	int				res;

	if (!(res = get_argument(op, &instruction)))
		return (-1);
	if (!(new = malloc(sizeof(t_process))))
	{
		free_instruction(&instruction);
		return (-1);
	}
	if (cpy_process(&new, proc) == EXIT_FAILURE)
	{
		free_instruction(&instruction);
		return (-1);
	}
	new->pc += (short)get_real_value(vm, proc, &instruction, 0) % IDX_MOD;
	new->pc = new->pc % MEM_SIZE + MEM_SIZE * (new->pc < 0);
	new->op_code = 0;
	new->next = NULL;
	new->id = ++(vm->nb_process);
	link_process(vm, new);
	print_debug(vm, op, res, proc);
	free_instruction(&instruction);
	return (res);
}
