/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_to_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:56:01 by lucdubos          #+#    #+#             */
/*   Updated: 2019/04/10 20:40:28 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			byte_encodage(t_asm *tasm, int n)
{
	char			*tmp;
	char			*tmp_hexa;
	int				i;

	i = -1;
	tmp = ft_strnew(8);
	while (++i < 3 && tasm->instr[n]->args[i])
	{
		if (tasm->instr[n]->args[i][0] == DIRECT_CHAR)
			ft_strcat(tmp, "10");
		else if (tasm->instr[n]->args[i][0] == 'r')
			ft_strcat(tmp, "01");
		else
			ft_strcat(tmp, "11");
	}
	while (ft_strlen(tmp) < 8)
		ft_strcat(tmp, "00");
	!(tmp_hexa = ft_binary_to_hexa(tmp)) ? free_and_exit(tasm) : 0;
	if (!(tasm->instr[n]->code_hexa = ft_strjoin1(
					tasm->instr[n]->code_hexa, " ")))
		free_and_exit(tasm);
	if (!(tasm->instr[n]->code_hexa = ft_strjoin3(
					tasm->instr[n]->code_hexa, tmp_hexa)))
		free_and_exit(tasm);
}

void			hexa_name(t_asm *tasm, int n)
{
	char			*tmp;

	if (!(tasm->instr[n]->code_hexa = ft_strnew(3)))
		free_and_exit(tasm);
	if (!(tmp = ft_itoa_base(g_op_tab[tasm->instr[n]->opcode].opcode, 16)))
		free_and_exit(tasm);
	ft_strcpy(tasm->instr[n]->code_hexa, tmp);
	if (ft_strlen(tasm->instr[n]->code_hexa) == 1)
	{
		if (!(tasm->instr[n]->code_hexa = ft_strjoin2(
						"0", tasm->instr[n]->code_hexa)))
			free_and_exit(tasm);
	}
	free(tmp);
}

char			*check_overflow(t_asm *tasm, int n, int i)
{
	int				size;
	char			*tmp;

	size = 0;
	if (tasm->instr[n]->args[i][0] == '%' || tasm->instr[n]->args[i][0] == 'r')
		size++;
	if (!(tmp = ft_itoa_base(ft_atoll(tasm->instr[n]->args[i] + size), 10)))
		free_and_exit(tasm);
	ft_printf("args : %s\n",tasm->instr[n]->args[i]);
	size += ft_strlen(&tasm->instr[n]->args[i][size]) - ft_strlen(tmp);
	if (ft_strcmp(&tasm->instr[n]->args[i][size], tmp) != 0)
	{
		tmp ? free(tmp) : 0;
		ft_printf("atoLL tmp : %d\n", ft_atoll(tmp));
		ft_printf("atoI tmp : %d\n", ft_atoi(tmp));
		if (tasm->instr[n]->args[i][size] == '-')
			tmp  = ft_strdup("0");
		else
			tmp  = ft_strdup("ffffffff");
		return (tmp);
	}
	free(tmp);
	return (NULL);
}

void			ft_arg_to_hexa(t_asm *tasm, int n, int type, int i)
{
	char			*tmp;
	size_t			size;

	if (!(tmp = check_overflow(tasm, n, i)))
	{
		if (tasm->instr[n]->args[i][0] == 'r'
				|| tasm->instr[n]->args[i][0] == '%')
			tmp = ft_itoa_base((unsigned int)
					ft_atoi(tasm->instr[n]->args[i] + 1), 16);
		else
			tmp = ft_itoa_base((unsigned int)ft_atoi(tasm->instr[n]->args[i]), 16);
		!tmp ? free_and_exit(tasm) : 0;
	}

	ft_printf("tmp : %s\n", tmp);
	size = size_by_type_instruction(type);
	if (ft_atoi(tasm->instr[n]->args[i]) < 0
		|| ft_atoi(tasm->instr[n]->args[i] + 1) < 0)
		ft_strcpy(tmp, &tmp[8 - (size * 2)]);
	if (ft_strlen(tmp) > size * 2)
		ft_strcpy(tmp, tmp + ft_strlen(tmp) - size * 2);
	ft_printf("premiere dec tmp : %s\n", tmp);
	!hexa_to_good_size_hexa(&tmp, size) ? free_and_exit(tasm) : 0;

	ft_printf("deuxieme dec tmp : %s\n", tmp);
	if (!(tasm->instr[n]->code_hexa = ft_strjoin1(tasm->instr[n]->code_hexa,
					" ")))
		free_and_exit(tasm);
	if (!(tasm->instr[n]->code_hexa = ft_strjoin3(tasm->instr[n]->code_hexa,
					tmp)))
		free_and_exit(tasm);
}

void			ft_label_to_hexa(t_asm *tasm, int n, int type, int i)
{
	int				size;
	char			*tmp;
	int				pos_l;

	pos_l = tasm->instr[tasm->instr[n]->pos_label[i]]
		->pos_first_byte - tasm->instr[n]->pos_first_byte
		+ tasm->instr[n]->operation_label[i];
	!(tmp = ft_itoa_base((unsigned int)pos_l, 16)) ? free_and_exit(tasm) : 0;
	while (ft_strlen(tmp) < 8)
		!(tmp = ft_strjoin2("0", tmp)) ? free_and_exit(tasm) : 0;
	size = size_by_type_instruction(type);
	ft_strcpy(tmp, &tmp[8 - (size * 2)]);
	hexa_to_good_size_hexa(&tmp, size);
	if (!(tasm->instr[n]->code_hexa = ft_strjoin1(tasm->instr[n]->code_hexa,
					" ")))
		free_and_exit(tasm);
	if (!(tasm->instr[n]->code_hexa = ft_strjoin1(tasm->instr[n]->code_hexa,
					tmp)))
		free_and_exit(tasm);
	free(tmp);
}

void			byte_instructions(t_asm *tasm, int n)
{
	int				i;

	i = 0;
	while (i < 3 && tasm->instr[n]->args[i])
	{
		if (tasm->instr[n]->args[i][0] == LABEL_CHAR)
			ft_label_to_hexa(tasm, n, IND_CODE, i);
		else if (tasm->instr[n]->args[i][0] == 'r')
			ft_arg_to_hexa(tasm, n, REG_CODE, i);
		else if (tasm->instr[n]->args[i][0] == DIRECT_CHAR)
		{
			if (tasm->instr[n]->args[i][1] == LABEL_CHAR)
				g_op_tab[tasm->instr[n]->opcode].half_size ?
				ft_label_to_hexa(tasm, n, IND_CODE, i) :
				ft_label_to_hexa(tasm, n, DIR_CODE, i);
			else
				g_op_tab[tasm->instr[n]->opcode].half_size ?
				ft_arg_to_hexa(tasm, n, IND_CODE, i) :
				ft_arg_to_hexa(tasm, n, DIR_CODE, i);
		}
		else
			ft_arg_to_hexa(tasm, n, IND_CODE, i);
		i++;
	}
}
