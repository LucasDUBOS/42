/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:01:40 by lucdubos          #+#    #+#             */
/*   Updated: 2018/10/16 18:59:20 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin1(char const *s1, char const *s2)
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
	return (concat);
}
