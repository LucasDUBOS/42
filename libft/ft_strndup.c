/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:11:42 by lucdubos          #+#    #+#             */
/*   Updated: 2018/09/04 17:11:44 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *str, int k)
{
	char	*cpy;

	if (!(cpy = ft_strnew(k + 1)))
		return (0);
	ft_strncpy(cpy, str, k);
	return (cpy);
}
