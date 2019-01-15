/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:47:10 by lucdubos          #+#    #+#             */
/*   Updated: 2018/09/17 15:59:06 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char *cpy;

	if (str == NULL)
		return (0);
	if (!(cpy = (char*)malloc(sizeof(*cpy) * (ft_strlen(str) + 1))))
		return (0);
	if (cpy == NULL)
		return (0);
	ft_strcpy(cpy, str);
	return (cpy);
}
