/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmaj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:22:46 by xgilbert          #+#    #+#             */
/*   Updated: 2017/11/14 17:38:43 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_putmaj(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}