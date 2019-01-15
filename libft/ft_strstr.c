/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:48:06 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/23 20:21:57 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int i2;

	i = 0;
	i2 = 0;
	if (to_find[0] == '\0')
		return ((char*)str);
	while (str[i] != '\0')
	{
		while (str[i] == to_find[i2] && str[i] != '\0')
		{
			i++;
			i2++;
		}
		if (to_find[i2] == '\0')
			return ((char*)(&str[i - i2]));
		else
			i = i - i2;
		i2 = 0;
		i++;
	}
	return (0);
}
