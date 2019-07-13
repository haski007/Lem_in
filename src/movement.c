/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:39:21 by pdemian           #+#    #+#             */
/*   Updated: 2019/07/11 17:39:44 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_room			*min_tube(t_room *room)
{
	t_list	*list;
	t_room	*tmp;
	t_room	*min_tube;
	int		min;

	min = 999;
	list = room->tubes;
	while (list)
	{
		tmp = *(t_room**)list->content;
		if (tmp->value < min && !tmp->busy)
		{
			min_tube = tmp;
			min = tmp->value;
		}
		list = list->next;
	}
	list = room->tubes;
	while (!ft_strequ((*(t_room**)list->content)->name, min_tube->name))
		list = list->next;
	return (*(t_room**)list->content);
}

t_list		*save_path(t_farm *farm, t_list *rooms)
{
	t_list	*list;
	t_list	*path;
	t_room	*room;

	path = NULL;
	list = rooms;
	while (list)
	{
		room = (t_room*)list->content;
		if (room->rank == 1)
		{
			ft_lstpush(&path, ft_lstnew(&room, sizeof(t_room*)));
			break ;
		}

		list = list->next;
	}
	while (room->rank != 2)
	{
		room->busy = 1;
		room = min_tube(room);
		ft_lstpush(&path, ft_lstnew(&room, sizeof(t_room*)));
	}
	return (path);
}

void			movement(t_farm *farm)
{
	t_list	*list;
	
	farm->path = NULL;
	while ((list = save_path(farm, farm->rooms)))
	{
		ft_lstpush(&farm->path, ft_lstnew(list, sizeof(t_list*)));
		// printf("%s\n", (*(t_room**)(*(t_list**)farm->path->content))->name);
	}
}