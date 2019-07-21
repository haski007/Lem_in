/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 16:46:28 by pdemian           #+#    #+#             */
/*   Updated: 2019/07/21 16:46:29 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			check_start_end(t_list **input)
{
	int		s;
	int		e;
	t_list	*list;

	s = 0;
	e = 0;
	list = *input;
	while (list)
	{
		if (ft_strequ((char*)list->content, "##start\n"))
			s++;
		else if (ft_strequ((char*)list->content, "##end\n"))
			e++;
		list = list->next;
	}
	if (s > 1)
		show_error("Too much starts, man");
	else if (e > 1)
		show_error("Too much ends, man");
	else if (s < 1)
		show_error("Man, where is your start room?");
	else if (e < 1)
		show_error("Man, where is your end room?");
}

void			validate_rooms(t_list **rooms)
{
	t_list	*list;
	t_room	*room;
	t_list	*tmp;
	int		n;
	int		c;

	list = *rooms;
	while (list)
	{
		room = (t_room*)list->content;
		n = 0;
		c = 0;
		tmp = *rooms;
		while (tmp)
		{
			if (ft_strequ(room->name, ((t_room*)tmp->content)->name))
				n++;
			if (room->x == ((t_room*)tmp->content)->x &&
			room->y == ((t_room*)tmp->content)->y)
				c++;
			tmp = tmp->next;
		}
		if (n > 1)
			show_error("There are the same names in different rooms");
		if (c > 1)
			show_error("There are the same coordinates in different rooms");
		list = list->next;
	}
}

void			validator(t_farm *farm)
{
	if (farm->ants < 1)
		show_error("Your count of ants is not normal...!");
	if (!farm->input)
		show_error("Seems like newline is in non valid place");
	validate_rooms(&farm->rooms);
	check_start_end(&farm->input);
}
