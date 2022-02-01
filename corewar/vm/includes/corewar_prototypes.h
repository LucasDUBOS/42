/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_prototypes.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:07:27 by xgilbert          #+#    #+#             */
/*   Updated: 2019/04/11 12:22:58 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_PROTOTYPES_H
# define COREWAR_PROTOTYPES_H

# include "../libft/libft/libft.h"
# include "corewar_structs.h"

int					to_big_endian(unsigned int lil_endian);
void				free_vm(t_vm *vm);
int					free_all_process(t_vm *vm);
void				free_and_quit(t_vm *vm, char *msg, int code);

int					init_vm(t_vm *vm);
int					fill_champ_data(t_vm *vm, t_champ *champ);
int					init_corewar(t_vm *vm);

int					args_are_valids(int ac, char **av);
int					fill_vm_with_argv(t_vm *vm, int ac, char **av);

int					print_debug(t_vm *vm, char *op, int size, t_process *proc);

int					exec_vm(t_vm *vm);
int					for_each_cycle(t_vm *vm);
int					clean_process_alive(t_vm *vm);
t_process			*elimination_a_la_batte_le_processus(t_vm *vm, int i);
void				creation_process_par_champ(t_vm *vm);
int					display_ending(t_vm *vm);

t_process			*new_process(void);
int					cpy_process(t_process **dst, t_process *src);
int					create_champ_process(t_vm *vm, int champ_pos);

int					get_nb_champs(t_vm *vm);
void				reverse_champ_ids(t_vm *vm);
t_champ				*get_champ_by_id(t_champ *champ_array, int id);
int					champ_id_exists(t_champ *champ_array, int id);
char				*get_op(char *arena, int pc, int op_id);
void				link_process(t_vm *vm, t_process *new_process);

#endif
