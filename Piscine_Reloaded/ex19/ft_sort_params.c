/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:31:05 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/07 14:36:54 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_strcmp(char **argv, int argc)
{
	char	*tmp;
	int		x;
	int		i;

	x = argc - 1;
	i = 0;
	while (1 < x)
	{
		while (argv[x][i] == argv[x - 1][i])
			i++;
		if ((argv[x - 1][i] - argv[x][i]) > 0)
		{
			tmp = argv[x - 1];
			argv[x - 1] = argv[x];
			argv[x] = tmp;
			x = argc - 1;
		}
		else
			x--;
		i = 0;
	}
}

int		main(int argc, char **argv)
{
	int i;
	int c;

	i = 1;
	c = 1;
	ft_strcmp(argv, argc);
	if (argv == 0)
		return (0);
	while (argc > c)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
		c++;
	}
	return (0);
}
