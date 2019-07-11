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

static void				heat_links(t_list **links, int i)
{
	t_list	*list;
	t_room	*tube;

	list = *links;
	while (list)
	{
		tube = *(t_room**)list->content;
		if (tube->value == -1)
			tube->value = i;
		list = list->next;
	}
}

void				heat_map(t_farm *farm)
{
	t_list	*list;
	t_room	*room;
	int		i;

	i = -1;
	while (++i < farm->N)
	{
		list = farm->rooms;
		while (list)
		{
			room = (t_room*)list->content;
			if (room->value == i)
				heat_links(&room->tubes, i + 1);
			list = list->next;
		}
	}
}