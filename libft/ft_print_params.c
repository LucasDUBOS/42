/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:07:23 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/28 19:10:20 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_params(int argc, char **argv)
{
	int i;

	i = 1;
	argc--;
	while (argc > 0)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
		argc--;
	}
}
