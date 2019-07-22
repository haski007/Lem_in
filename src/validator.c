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

char			*make_step(int ant, char *name)
{
	char	*str;
	char	*tmp;
	char	*tmp2;

	str = ft_strdup("L");
	tmp2 = ft_itoa(ant);
	tmp = ft_strjoin(str, tmp2);
	free(tmp2);
	free(str);
	str = ft_strjoin(tmp, "-");
	free(tmp);
	tmp = ft_strjoin(str, name);
	free(str);
	return (tmp);
}

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
		if (ft_strequ((char*)list->content, "##start"))
			s++;
		else if (ft_strequ((char*)list->content, "##end"))
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

void			validate_rooms(t_list **rooms, t_list *list)
{
	t_room	*room;
	t_list	*tmp;
	int		n;
	int		c;

	while (list)
	{
		room = (t_room*)list->content;
		n = 0;
		c = 0;
		tmp = *rooms;
		while (tmp)
		{
			if (ft_strequ(room->name, ROOM->name))
				n++;
			if (room->x == ROOM->x && room->y == ROOM->y)
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
	t_list	*norm;

	if (farm->ants < 1)
		show_error("Your count of ants is not normal...!");
	if (!farm->input)
		show_error("Seems like newline is in non valid place");
	norm = farm->rooms;
	validate_rooms(&farm->rooms, norm);
	check_start_end(&farm->input);
}
