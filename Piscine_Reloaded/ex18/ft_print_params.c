/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:21:36 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/07 14:23:16 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *argv)
{
	while (*argv != '\0')
	{
		ft_putchar(*argv);
		argv++;
	}
}

int		main(int argc, char **argv)
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
	return (0);
}
