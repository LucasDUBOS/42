/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:04:08 by lucdubos          #+#    #+#             */
/*   Updated: 2018/09/17 14:44:41 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin3(char const *s1, char const *s2)
{
	int		i;
	int		a;
	char	*concat;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	a = ft_strlen(s1);
	i = ft_strlen(s2);
	if (!(concat = (char*)malloc(sizeof(*concat) * (a + i + 1))))
		return (0);
	concat = ft_strcpy(concat, s1);
	concat = ft_strcat(concat, s2);
	free((char*)s1);
	free((char*)s2);
	return (concat);
}
