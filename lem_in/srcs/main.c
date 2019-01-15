/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:51:27 by xgilbert          #+#    #+#             */
/*   Updated: 2019/01/14 15:08:13 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			init_lem(t_struct *s)
{
	if ((s->str = ft_strnew(0)) == 0)
		exit(0);
	s->nb_links = 0;
	s->nb_rooms = 0;
	s->nb_path = 1;
	s->nb_coups = 1;
	s->path_found = 0;
	return (1);
}

void		first_part(t_struct *s)
{
	if (check_errors(s, 0, 0, 0) == 0)
	{
		free(s->str);
		free_tab(s);
		ft_printf("ERROR\n");
		exit(0);
	}
	get_info(s);
	if (!(parsing(s)))
	{
		ft_printf("ERROR\n");
		exit(0);
	}
	modif_matrix(s);
}

void		second_part(t_struct *s)
{
	path_finding(s);
	sort_path(s);
	elimination(s);
	if (!(s->fpath))
	{
		free(s->str);
		free_tab(s);
		free_rooms(s);
		ft_printf("Pas de chemin menant a la sortie\n");
		exit(0);
	}
}

int			main(int argc, const char **argv)
{
	t_struct	s;

	if (argc < 1 || !(argv[0]))
		return (0);
	init_lem(&s);
	get_next_line(0, &s.str);
	s.tab = ft_strsplit(s.str, '\n');
	first_part(&s);
	second_part(&s);
	ft_printf("%s\n", s.str);
	ants_going_in(&s);
	free_all(&s);
	return (0);
}
