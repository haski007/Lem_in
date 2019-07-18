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

int			find_end(t_list **queue, t_room *room, int i)
{
	t_list	*tubes;
	t_room	*tube;
	t_room	*tmp;

	tubes = room->tubes;
	tube = NULL;
	while (tubes)
	{
		if (TUBE->busy != i && !TUBE->busy2)
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

t_list			*get_list(t_room *room, int i)
{
	t_list	*list;

	list = NULL;
	if (room->rank != 2)
		return (0);
	while (room->rank != 1)
	{
		// printf("%s\n", room->name);
		ft_lstadd(&list, ft_lstnew(&room, sizeof(t_room*)));
		room->busy = (room->rank != 2) ? i + 1 : 0;
		room->busy2 = (room->rank != 2) ? 1 : 0;
		room = room->parent;
	}
	room->busy = i + 1;
	return (list);
}

t_list			*get_path(t_farm *farm, int i)
{
	t_list		*list;
	t_room		*room;
	t_list		*queue;
	t_list		*tmp;

	list = farm->rooms;
	queue = NULL;
	while (list)
	{
		room = (t_room*)list->content;
		if (room->rank == 1)
			break ;
		list = list->next;
	}
	ft_lstadd(&queue, ft_lstnew(&room, sizeof(t_room*)));
	tmp = queue;
	while (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		room = (*(t_room**)tmp->content);
		if (find_end(&queue, room, i))
			break ;
		tmp = queue;
	}
	return (get_list(room, i));
}

void			get_paths(t_farm *farm)
{
	t_list	*list;
	t_list	*path;
	int		i;
	
	i = 0;
	farm->path = NULL;
	while ((list = get_path(farm, ++i)))
	{
		ft_lstpush(&farm->path, ft_lstnew(list, sizeof(t_list)));
		free(list);
	}
	count_distanse(&farm->path);
	cut_the_path(farm);
}