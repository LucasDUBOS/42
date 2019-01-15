/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:07:46 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/15 13:52:54 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int stock;

	i = 0;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	while (s1[i] == s2[i])
	{
		i++;
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
	}
	stock = ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (stock);
}
