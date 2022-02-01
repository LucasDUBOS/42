/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:12:16 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/09 16:50:29 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			free_vm(t_vm *vm)
{
	if (vm->process_list)
		free_all_process(vm);
	if (vm->champs)
		ft_memdel((void**)&vm->champs);
	if (vm->arena)
		ft_memdel((void**)&vm->arena);
}
