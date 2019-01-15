/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:32:12 by lucdubos          #+#    #+#             */
/*   Updated: 2018/01/31 18:23:52 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <limits.h>

char			*ft_strjoin_and_free(char *str, char const *buffer)
{
	char *new_str;

	new_str = ft_strjoin(str, buffer);
	free((char*)str);
	return (new_str);
}

static int		check_errors(int fd, char **str, char **line, char **buffer)
{
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || fd > OPEN_MAX)
		return (0);
	if (!*str)
		*str = ft_strnew(1);
	*buffer = ft_strnew(BUFF_SIZE);
	return (1);
}

static int		create_str(int fd, char **str, int size, char *buffer)
{
	int		i;

	while (size > 0)
	{
		buffer[size] = '\0';
		*str = ft_strjoin_and_free(*str, buffer);
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

static void		cpy(char **line, char *str, int k)
{
	*line = ft_strnew(k);
	*line = ft_strncpy(*line, str, (k));
	str = ft_strcpy(str, &str[k]);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str[OPEN_MAX];
	char			*buffer;
	int				k;

	if ((check_errors(fd, &str[fd], line, &buffer)) == 0
			|| (k = read(fd, buffer, BUFF_SIZE)) == -1)
		return (-1);
	create_str(fd, &str[fd], k, buffer);
	free(buffer);
	k = -1;
	while (str[fd][++k])
	{
		if (str[fd][k] == '\n')
		{
			str[fd][k++] = '\0';
			cpy(line, str[fd], k);
			return (1);
		}
	}
	if (str[fd][0] == '\0')
		return (0);
	cpy(line, str[fd], k);
	return (1);
}
