/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:09:13 by xgilbert          #+#    #+#             */
/*   Updated: 2017/11/09 16:08:41 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*arr;

	i = 0;
	arr = (char*)malloc(sizeof(*arr) * (ft_strlen(str) + 1));
	if (arr == NULL)
		return (0);
	while (str[i])
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
