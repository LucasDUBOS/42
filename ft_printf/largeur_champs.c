/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largeur_champs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:13:49 by lucdubos          #+#    #+#             */
/*   Updated: 2018/09/17 15:13:50 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		largeur_champs(const char *format, t_format *s)
{
	char		*temp;
	int			len;
	int			i;

	i = s->k;
	if (s->att_moins || s->att_zero)
		return ;
	while ((format[i] < '1' || format[i] > '9') && (format[i] != s->conv))
		i++;
	if (format[i - 1] == '.')
		return ;
	len = i;
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	temp = ft_strndup(&format[len], i - len);
	len = ft_atoi(temp) - ft_strlen(s->tmp);
	free(temp);
	if (len < 0)
		return ;
	temp = ft_strnew(len);
	temp[len--] = '\0';
	while (len >= 0)
		temp[len--] = ' ';
	s->tmp = ft_strjoin3(temp, s->tmp);
}
