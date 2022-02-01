/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_champs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:42:15 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/09 14:51:46 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				get_nb_champs(t_vm *vm)
{
	int			nb;
	static int	used = 0;

	if (used == 1)
		return (vm->nb_champs);
	nb = 0;
	while ((nb < MAX_PLAYERS) && (vm->champs[nb].id != -1))
		nb++;
	used = 1;
	return (nb);
}
