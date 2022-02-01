/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:32:20 by xgilbert          #+#    #+#             */
/*   Updated: 2019/04/09 20:11:49 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		usage(void)
{
	ft_printf("Usage : ./asm [champion.s]\n");
	exit(0);
}

char		*check_file(t_asm *tasm, int fd, char *str)
{
	char			*buffer;

//	tasm->instr = NULL;
	if (ft_strcmp(&str[ft_strlen(str) - 2], ".s"))
		usage();
	if (fd < 0)
	{
		ft_printf("Thanks to send a correct file\n");
		free_and_exit(tasm);
	}
	!(buffer = ft_strnew(BUFF_SIZE)) ? free_and_exit(tasm) : 0;
	read(fd, buffer, BUFF_SIZE);
	{
		if (buffer[0] != '.' && !ft_isspace(buffer[0])
		&& buffer[0] != '#')
		{
			ft_printf("[.name] unknown\n");
			free(buffer);
			exit(0);
		}
	}
	return (buffer);
}

int			assembler(t_asm *tasm)
{
	parsing(tasm);
	if (tasm->instr[0])
		to_hexa(tasm);
	return (1);
}

int			main(int ac, char **av)
{
	t_asm		tasm;
	char		*file;
	int			fd;

	if (ac < 2)
		usage();
	fd = open(av[1], O_RDONLY);
	file = check_file(&tasm, fd, av[1]);
	if (ft_getfile(fd, &file) <= 0)
	{
		free(file);
		return (0);
	}
	if (!(tasm.file = split_file(file, '\n')))
	{
		free(file);
		return (0);
	}
	free(file);
	assembler(&tasm);
/*int n = 0;
ft_printf("code hexa \n");
	while (tasm.instr[n])
	{
		if(tasm.instr[n]->name)
			ft_printf("%s ",tasm.instr[n]->code_hexa);
		n++;
	}
	ft_putendl("");*/
	bytes_to_file(&tasm, av[1]);
	close(fd);
	free_all(&tasm);
	return (0);
}
