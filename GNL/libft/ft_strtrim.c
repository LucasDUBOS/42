/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:29:43 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/20 20:02:00 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_putend(int i, int j, char const *s, int len)
{
	char *ptr;

	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
		j++;
	}
	while (s[i] != '\0')
	{
		len++;
		i++;
	}
	i--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i--;
		len--;
	}
	if (!(ptr = (char*)malloc(sizeof(*ptr) * (len + 1))))
		return (NULL);
	i = 0;
	while (len-- > 0)
		ptr[i++] = s[j++];
	ptr[i] = '\0';
	return (ptr);
}

char		*ft_strtrim(char const *s)
{
	char	*ptr;
	int		i;
	int		len;
	int		j;

	if (s == NULL)
		return (0);
	i = 0;
	len = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			j++;
		i++;
	}
	if (j == i)
	{
		if ((ptr = (char*)malloc(sizeof(*ptr) * 1)) == NULL)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	ptr = ft_putend(0, 0, s, len);
	return (ptr);
}
