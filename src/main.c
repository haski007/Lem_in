	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:23:28 by pdemian           #+#    #+#             */
/*   Updated: 2019/06/28 16:46:36 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void		print_all_err(void)
{
	int	i;

	i = -1;
	while (++i < 100)
		printf("%s\n", strerror(i));
}

void			paint_farm(t_list *list)
{
	while (list)
	{
		printf("%zu) ", list->content_size);
		printf("%s", list->content);
		list = list->next;
	}
}

// void		paint_rooms(t_rooms room)
// {
// 	while ()
// 	{
// 		printf("%s x = %d, y = %d\n", room->name, room->x, room->y);
// 		room = room->next;
// 	}
// }

int			main(void)
{
	t_farm	farm;
	t_rooms	room;
	t_list	*list;

	list = save_farm(&farm);
	// if (!list)
	// 	ft_putstr(strerror(9));
	print_all_err();
	// paint_rooms(room);
	// paint_farm(list);
	return (0);
}
