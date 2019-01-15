/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:32:12 by lucdubos          #+#    #+#             */
/*   Updated: 2018/10/24 12:01:27 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <limits.h>

static int		gnl_check_errors(int fd, char **str, char **line, char **buffer)
{
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || fd > OPEN_MAX)
		return (0);
	if (!*str)
		*str = ft_strnew(1);
	*buffer = ft_strnew(BUFF_SIZE);
	return (1);
}

static int		gnl_create_str(int fd, char **str, int size, char *buffer)
{
	int		i;

	while (size > 0)
	{
		buffer[size] = '\0';
		*str = ft_strjoin1(*str, buffer);
		i = -1;
		while (buffer[++i])
		{
			if (buffer[i] == '\n')
				return (0);
		}
		size = read(fd, buffer, BUFF_SIZE);
	}
	return (0);
}

static void		gnl_cpy(char **line, char *str, int k)
{
	*line = ft_strnew(k);
	*line = ft_strncpy(*line, str, (k));
	str = ft_strcpy(str, &str[k]);
}

int				get_next_line_cut(char *str, int *k, char **line)
{
	if (str[*k] == '\n')
	{
		str[*k] = '\0';
		*k = *k + 1;
		gnl_cpy(line, str, *k);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str[OPEN_MAX];
	char			*buffer;
	int				k;

	if ((gnl_check_errors(fd, &str[fd], line, &buffer)) == 0
			|| (k = read(fd, buffer, BUFF_SIZE)) == -1)
		return (-1);
	gnl_create_str(fd, &str[fd], k, buffer);
	free(buffer);
	k = -1;
	while (str[fd][++k])
	{
		if (get_next_line_cut(str[fd], &k, line) == 1)
			return (1);
	}
	if (str[fd][0] == '\0')
	{
		free(str[fd]);
		return (0);
	}
	gnl_cpy(line, str[fd], k);
	return (1);
}
