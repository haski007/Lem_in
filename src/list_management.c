/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:34:33 by pdemian           #+#    #+#             */
/*   Updated: 2019/07/04 17:34:35 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_llist				*newllst(char *name, char *tube)
{
	t_llist		*list;

	list = (t_llist*)malloc(sizeof(t_rlist));
	if (ft_strcmp(ft_strchr(tube, '-'), name) == 0)
		list->tube = ft_strcdup(tube, '-');
	else
		list->tube = ft_strdup(ft_strchr(tube, '-'));
	list->next = NULL;
	return (list);
}

t_rlist				*newrlst(t_room *room)
{
	t_rlist		*list;

	list = (t_rlist*)malloc(sizeof(t_rlist));
	list->room = room;
	list->next = NULL;
	return (list);
}