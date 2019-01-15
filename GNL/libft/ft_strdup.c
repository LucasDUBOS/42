/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:47:10 by lucdubos          #+#    #+#             */
/*   Updated: 2018/01/09 12:15:15 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s1)
{
	char *cpy;

	cpy = (char*)malloc(sizeof(*cpy) * (ft_strlen(s1) + 1));
	if (cpy == NULL)
		return (0);
	ft_strcpy(cpy, s1);
	return (cpy);
}
