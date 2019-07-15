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

int			make_flex(t_list **queue, t_room *room)
{
	t_list	*links;
	t_room	*tube;
	t_list	*list;

	tube = NULL;
	links = room->tubes;
	while (links)
	{
		if (!(*(t_room**)links->content)->busy && !ft_strequ(room->name, (*(t_room**)links->content)->name))
		{
			tube = *(t_room**)links->content;
			tube->parent = room;
				ft_lstadd(queue, ft_lstnew(&tube, sizeof(t_room*)));
			if (tube->rank == 2)
				break ;
		}
		links = links->next;
	}
	if (!tube)
		return (0);
	else if (tube->rank == 2)
	{
		ft_lstdel(queue, ft_lstfree);
		queue = NULL;
		return (1);
	}
	else
		ft_lstdelast(queue);
	return (1);
}

t_list		*get_path(t_room *room)
{
	t_list	*path;
	t_room	*tmp;

	path = NULL;
	while (room->rank != 1)
	{
		tmp = room;
		ft_lstadd(&path, ft_lstnew(&room, sizeof(t_room*)));
		room = room->parent;
		tmp->parent = NULL;
		room->busy = 1;
	}
	return (path);
}

t_list		*save_path(t_farm *farm, t_list *rooms)
{
	t_list	*list;
	t_room	*room;
	t_list	*queue;
	t_list	*tmp;

	queue = NULL;
	list = rooms;
	while (list)
	{
		room = (t_room*)list->content;
		if (room->rank == 1)
		{
			ft_lstpush(&queue, ft_lstnew(&room, sizeof(t_room*)));
			break ;
		}
		list = list->next;
	}
	tmp = queue;
	while (tmp)
	{
		while (tmp->next && tmp)
			tmp = tmp->next;
		room = *(t_room**)tmp->content;
		if (!make_flex(&queue, room))
			return (0);
		tmp = queue;
	}
	list = rooms;
	while (((t_room*)list->content)->rank != 2)
		list = list->next;
	return (get_path((t_room*)list->content));
}

void			movement(t_farm *farm)
{
	t_list	*list;
	
	farm->path = NULL;
	while ((list = save_path(farm, farm->rooms)))
	{
		ft_lstpush(&farm->path, ft_lstnew(list, sizeof(t_list)));
		free(list);
		// printf("%s\n", (*(t_room**)(*(t_list**)farm->path->content))->name);
	}
}