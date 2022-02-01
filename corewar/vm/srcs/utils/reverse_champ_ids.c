/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_champ_ids.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:42:20 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/09 14:44:38 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			reverse_champ_ids(t_vm *vm)
{
	int			i;

	i = 0;
	while (i < vm->nb_champs)
		vm->champs[i++].id *= -1;
}
