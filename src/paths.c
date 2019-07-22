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

t_room		*find_start(t_list *list)
{
	while (list)
	{
		if (((t_room*)list->content)->rank == 1)
			return ((t_room*)list->content);
		list = list->next;
	}
	return (0);
}

int			find_end(t_list **queue, t_room *room, int i)
{
	t_list	*tubes;
	t_room	*tube;

	tubes = room->tubes;
	tube = NULL;
	while (tubes)
	{
		if ((TUBE->busy != i && !TUBE->busy2))
		{
			tube = *(t_room**)tubes->content;
			tube->parent = room;
			tube->busy = i;
			ft_lstadd(queue, ft_lstnew(&tube, sizeof(t_room*)));
		}
		tubes = tubes->next;
	}
	if (room->rank == 2)
	{
		return (1);
		ft_lstdel(queue, ft_lstfree);
	}
	else
		ft_lstdelast(queue);
	return (0);
}

t_list		*get_list(t_room *room, int i)
{
	t_list	*list;

	list = NULL;
	if (room->rank != 2)
		return (0);
	if (room->parent->rank == 1)
	{
		ft_lstadd(&list, ft_lstnew(&room, sizeof(t_room*)));
		ft_lstadd(&list, ft_lstnew(&room->parent, sizeof(t_room*)));
	}
	else
		while (room->rank != 1)
		{
			ft_lstadd(&list, ft_lstnew(&room, sizeof(t_room*)));
			room->busy = (room->rank != 2) ? i + 1 : 0;
			room->busy2 = (room->rank != 2) ? 1 : 0;
			room = room->parent;
		}
	room->busy = i + 1;
	return (list);
}

t_list		*get_path(t_farm *farm, int i)
{
	t_list		*list;
	t_room		*room;
	t_list		*queue;

	list = farm->rooms;
	queue = NULL;
	room = find_start(list);
	ft_lstadd(&queue, ft_lstnew(&room, sizeof(t_room*)));
	list = queue;
	while (list)
	{
		while (list->next)
			list = list->next;
		room = (*(t_room**)list->content);
		if (find_end(&queue, room, i))
		{
			ft_lstdel(&queue, ft_lstfree);
			break ;
		}
		list = queue;
	}
	return (get_list(room, i));
}

void		get_paths(t_farm *farm)
{
	t_list	*list;
	int		i;

	i = 0;
	farm->path = NULL;
	while ((list = get_path(farm, ++i)))
	{
		ft_lstpush(&farm->path, ft_lstnew(list, sizeof(t_list)));
		free(list);
	}
	if (!farm->path)
		show_error("There aren't valid paths");
	count_distanse(&farm->path);
}
