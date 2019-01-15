/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stockwstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:04:29 by lucdubos          #+#    #+#             */
/*   Updated: 2018/09/17 15:06:31 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_stockwstr(wchar_t *wstr)
{
	char		*str;
	char		*str2;
	int			i;

	i = 0;
	if (wstr[i])
	{
		if ((str = ft_stockwchar(wstr[i++])) == 0)
			return (0);
	}
	while (wstr[i])
	{
		if ((str2 = ft_stockwchar(wstr[i++])) == NULL)
			return (NULL);
		str = ft_strjoin3(str, str2);
	}
	return (str);
}
