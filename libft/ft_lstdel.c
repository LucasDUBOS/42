/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:25:02 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/17 20:09:07 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *tmp;
	t_list *listnext;

	tmp = *alst;
	while (tmp != NULL)
	{
		listnext = tmp->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = listnext;
	}
	*alst = NULL;
}
