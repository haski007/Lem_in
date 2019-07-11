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

static t_room			*min_value(t_room *room)
{
	t_list	*list;
	t_room	*tube;
	t_room	*min_tube;
	int		min;

	if (room->rank == 2)
		return (0);
	min = 999;
	list = room->tubes;
	while (list)
	{
		tube = *(t_room**)list->content;
		if (tube->value < min)
		{
			min_tube = tube;
			min = tube->value;
		}
		list = list->next;
	}
	return (min_tube);
}

void			movement(t_farm *farm , t_list **rooms)
{
	t_list	*list;
	t_room	*room;
	t_room	*tube;
	int		N;
	int		i;
	int		end;
	
	i = farm->ants;
	N = 1;
	end = 0;
	tube = NULL;
	while (end < i)
	{
		list = *rooms;
		while (list)
		{
			room = (!tube) ? (t_room*)list->content : tube;
			if (room->rank == 1 && farm->ants)
			{
				tube = min_value(room);
				tube->ant = N;
				farm->ants--;
				printf("L%d-%s \n", N, tube->name);
				break ;
			}
			else if (room->ant == N)
			{
				room->ant = 0;
				if (!(tube = min_value(room)))
				{
					end++;
					break ;
				}
				tube->ant = N;
				printf("L%d-%s \n", N, tube->name);
			}
			list = list->next;
		}
	}
}