/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:19:21 by lucdubos          #+#    #+#             */
/*   Updated: 2018/10/22 18:25:47 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin0(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (s1 != NULL && s2 != NULL)
	{
		i = 0;
		j = 0;
		if (!(ptr = (char*)malloc(sizeof(*ptr) *
				((ft_strlen(s1) + ft_strlen(s2)) + 1))))
			return (NULL);
		while (s1[i] != '\0')
		{
			ptr[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
			ptr[i++] = s2[j++];
		ptr[i] = '\0';
		return (ptr);
	}
	return (0);
}
