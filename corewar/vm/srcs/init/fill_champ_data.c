/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_champ_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:15:04 by akhercha          #+#    #+#             */
/*   Updated: 2019/04/11 12:27:11 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	champ_data_is_valid(t_champ_data *data, int len)
{
	return (!((to_big_endian(data->header.magic) != COREWAR_EXEC_MAGIC)
		|| (to_big_endian(data->header.prog_size) > CHAMP_MAX_SIZE)
		|| (len < (PROG_NAME_LENGTH + 1 + COM_LENGTH + 1 + AT_LEAST_ONE_OP))));
}

static int	fill_buffer(t_mem *buffer, t_mem *tmp, int bytes_read,
	int *offset)
{
	int		i;

	i = 0;
	while (i < bytes_read)
	{
		buffer[*offset + i] = tmp[i];
		i++;
	}
	*offset += i;
	return (EXIT_SUCCESS);
}

static int	read_champ(t_vm *vm, int fd, t_mem *buffer, t_mem *tmp)
{
	int		bytes_read;
	int		offset;

	offset = 0;
	bytes_read = 0;
	while (((bytes_read = read(fd, tmp, sizeof(t_header)
		+ CHAMP_MAX_SIZE)) > 0))
	{
		if ((offset + bytes_read) > (int)sizeof(t_header) + CHAMP_MAX_SIZE)
			free_and_quit(vm, "Error: champion too big.", EXIT_FAILURE);
		fill_buffer(buffer, tmp, bytes_read, &offset);
	}
	return (offset);
}

int			fill_champ_data(t_vm *vm, t_champ *champ)
{
	int		fd;
	int		len;
	t_mem	*buffer;
	t_mem	*tmp;

	fd = open(champ->filepath, O_RDONLY);
	if (fd <= 2)
		free_and_quit(vm, "Error: couldn't open .cor file.", EXIT_FAILURE);
	if (!(buffer = ft_memalloc(sizeof(t_header) + CHAMP_MAX_SIZE)))
		return (-1);
	if (!(tmp = ft_memalloc(sizeof(t_header) + CHAMP_MAX_SIZE)))
	{
		ft_memdel((void**)&buffer);
		return (-1);
	}
	len = read_champ(vm, fd, buffer, tmp);
	ft_memcpy(&(champ->data), buffer, sizeof(t_header) + CHAMP_MAX_SIZE);
	close(fd);
	ft_memdel((void**)&buffer);
	ft_memdel((void**)&tmp);
	return (!(champ_data_is_valid(&(champ->data), len)));
}
