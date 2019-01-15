/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:05:10 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/07 17:13:36 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

int		main(int argc, char **argv)
{
	char	buffer[1];
	int		fdin;
	int		nbread;

	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (0);
	}
	if (argc == 1)
	{
		ft_putstr("File name missing.\n");
		return (0);
	}
	fdin = open(argv[1], O_RDONLY);
	nbread = read(fdin, buffer, 1);
	while (nbread > 0)
	{
		write(1, buffer, nbread);
		nbread = read(fdin, buffer, 1);
	}
	close(fdin);
	return (0);
}
