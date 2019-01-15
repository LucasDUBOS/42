/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:38:22 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/17 20:10:00 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *debutliste;
	t_list *newlist;
	t_list *tmp;

	tmp = f(lst);
	newlist = ft_lstnew(tmp->content, tmp->content_size);
	if (newlist == NULL)
		return (NULL);
	debutliste = newlist;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp = f(lst);
		newlist->next = ft_lstnew(tmp->content, tmp->content_size);
		if (newlist->next == NULL)
			return (NULL);
		lst = lst->next;
		newlist = newlist->next;
	}
	newlist->next = NULL;
	return (debutliste);
}
