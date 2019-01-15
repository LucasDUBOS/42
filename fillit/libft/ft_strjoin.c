/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:40:03 by xgilbert          #+#    #+#             */
/*   Updated: 2017/11/20 18:29:39 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		a;
	char	*concat;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	a = ft_strlen(s1);
	i = ft_strlen(s2);
	concat = (char*)malloc(sizeof(*concat) * (a + i));
	if (concat == NULL)
		return (0);
	i = 0;
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		concat[i++] = s2[j++];
	concat[i] = '\0';
	return (concat);
}
