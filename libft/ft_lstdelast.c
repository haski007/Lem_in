/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:56:48 by pdemian           #+#    #+#             */
/*   Updated: 2019/07/12 15:56:50 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdelast(t_list **alst)
{
	t_list	*tmp;
	t_list	*list;

	if (!alst || !*alst)
		return ;
	list = *alst;
	if (list->next)
	{
		while (list->next->next)
			list = (list)->next;
		tmp = list;
		list = list->next;
		free(list->content);
		list->content_size = 0;
		free(list);
		list = NULL;
		tmp->next = NULL;
	}
	else
	{
		free(list->content);
		list->content_size = 0;
		free(list);
		list = NULL;
		alst = NULL;
	}
}
