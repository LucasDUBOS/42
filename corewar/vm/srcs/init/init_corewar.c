/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:01:32 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/11 12:21:26 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	add_to_arena(t_vm *vm, t_champ *champ, int index_champ,
	int total_champs)
{
	int		position;

	position = (MEM_SIZE / total_champs);
	ft_memcpy(&(vm->arena[index_champ * position]), &(champ->data.content),
		to_big_endian(champ->data.header.prog_size) + 1);
	return (EXIT_SUCCESS);
}

int			init_corewar(t_vm *vm)
{
	int		i;
	int		ret;

	reverse_champ_ids(vm);
	i = 0;
	while (i < vm->nb_champs)
	{
		ret = fill_champ_data(vm, &(vm->champs[i]));
		if (ret == -1)
			return (EXIT_FAILURE);
		if (ret == EXIT_FAILURE)
			free_and_quit(vm, "Error: bad binary or champion too big.",
				EXIT_FAILURE);
		add_to_arena(vm, &(vm->champs[i]), i, vm->nb_champs);
		if (create_champ_process(vm, i) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
