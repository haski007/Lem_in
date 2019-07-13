/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 19:54:54 by pdemian           #+#    #+#             */
/*   Updated: 2019/07/13 19:54:55 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void			ft_lstpush(t_list **alst, t_list *new)
{
	t_list	*list;

	if (!new)
		return;
	list = *alst;
	if (!list)
	{
		*alst = new;
		return ;
	}
	while (list->next)
		list = list->next;
	list->next = new;
}