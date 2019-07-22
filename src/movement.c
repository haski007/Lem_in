/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:36:24 by pdemian           #+#    #+#             */
/*   Updated: 2019/07/16 21:36:26 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_ant		*make_ant(t_room *room, int n, int i)
{
	t_ant *ant;

	ant = (t_ant*)malloc(sizeof(t_ant));
	ant->n = n;
	ant->room = room;
	ant->row = i;
	return (ant);
}

int			start(t_farm *farm, t_list **queue, t_list **paths)
{
	t_list			*path;
	t_ant			*ant;
	int				i;
	static int		n = 0;

	i = 0;
	path = *paths;
	while (path && farm->ants)
	{
		if (!valid_path(farm, (t_list*)path->content))
			break ;
		farm->ants--;
		ft_lstadd(queue, ft_lstnew(ant = make_ant(*(t_room**)
		((t_list*)path->content)->content, ++n, ++i), sizeof(t_ant)));
		free(ant);
		path = path->next;
	}
	return (1);
}

int			move_ant(t_farm *farm, t_list **queue, t_ant *ant, t_list *path)
{
	t_list	*list;
	t_ant	*m;

	list = path;
	while (list)
	{
		if (ant->room->rank == 2 &&
		ft_strequ((*(t_room**)list->content)->name, ant->room->name))
		{
			print_move(farm, ant, ant->room);
			ft_lstdelast(queue);
			return (1);
		}
		else if (ft_strequ((*(t_room**)list->content)->name, ant->room->name))
		{
			print_move(farm, ant, ant->room);
			ft_lstadd(queue, ft_lstnew(m = make_ant(*(t_room**)
			list->next->content, ant->n, ant->row), sizeof(t_ant)));
			free(m);
			ft_lstdelast(queue);
			return (0);
		}
		list = list->next;
	}
	return (0);
}

int			find_move(t_farm *farm, t_list **queue, int end)
{
	int		fuck;
	t_list	*paths;
	t_list	*tmp;
	int		i;

	paths = farm->path;
	start(farm, queue, &paths);
	fuck = ((t_ant*)(*queue)->content)->n;
	tmp = *queue;
	while (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		i = 0;
		paths = farm->path;
		while (++i < ((t_ant*)tmp->content)->row)
			paths = paths->next;
		i = end;
		end -= move_ant(farm, queue,
		(t_ant*)tmp->content, (t_list*)paths->content);
		tmp = *queue;
		if (!tmp || (((t_ant*)(*queue)->content)->n == fuck && end == i))
			break ;
	}
	return (end);
}

void		movement(t_farm *farm)
{
	t_list	*queue;
	int		end;

	end = farm->ants;
	queue = NULL;
	while (end > 0)
	{
		end = find_move(farm, &queue, end);
		if (!farm->flags.s)
			ft_printf("\n");
		farm->res++;
	}
}
