/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 18:08:49 by pdemian           #+#    #+#             */
/*   Updated: 2019/07/04 18:08:51 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int			heat_and_save(t_list **queue, t_room *room, int i)
{
	t_list	*links;
	t_room	*tube;
	t_list	*list;

	links = room->tubes;
	while (links)
	{
		tube = *(t_room**)links->content;
		if (tube->value == -1)
		{
			tube->value = i;
			ft_lstadd(queue, ft_lstnew(&tube, sizeof(t_room*)));
			// printf("%s\n", (*(t_room**)(*queue)->content)->name);
		}
		links = links->next;
	}
	if (room->rank != 2 && (*queue)->next)
	{
		ft_lstdelast(queue);
		return (0);
	}
	else if (room->rank != 2)
	{
		ft_lstdelast(queue);
		return (1);
	}
	return (0);
}

void				heat_map(t_farm *farm)
{
	t_list	*list;
	t_room	*room;
	t_list	*tmp;
	
	farm->queue = NULL;
	list = farm->rooms;
	while (list)
	{
		room = (t_room*)list->content;
		if (room->rank == 2)
			break ;
		list = list->next;
	}
	heat_and_save(&farm->queue, room, room->value + 1);
	tmp = farm->queue;
	while (tmp && !tmp->next)
	{
		room = *(t_room**)tmp->content;
		if ((heat_and_save(&farm->queue, room, room->value + 1)))
		{
			tmp->next = NULL;
			farm->queue = NULL;
		}
		tmp = farm->queue;
	}
	while (tmp && tmp->next)
	{
		while (tmp->next && tmp)
			tmp = tmp->next;
		room = *(t_room**)tmp->content;
		heat_and_save(&farm->queue, room, room->value + 1);
		tmp = farm->queue;
	}
}