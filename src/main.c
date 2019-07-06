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
	while (++i < 107)
		printf("%d) %s\n", i, strerror(i));
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

void			paint_rooms(t_list *rooms)
{
	t_room	*room;

	while (rooms)
	{
		room = (t_room*)(rooms->content);
		printf("%s\n", room->name);
		rooms = rooms->next;
	}
}

// void			paint_links(t_llist *llist)
// {
// 	int		i;

// 	i = 0;
// 	while (llist)
// 	{
// 		printf("link %d%8s\n", ++i, llist->tube);
// 		llist = llist->next;
// 	}
// }

static void		free_list(t_list **rooms)
{
	t_list	*list;
	t_list	*tmp;

	list = *rooms;
	while (list)
	{
		tmp = list->next;
		ft_bzero(&list->content, sizeof(t_room));
		free(list);
		list = tmp;
	}
	rooms = NULL;
}

int				main(void)
{
	t_farm	farm;

	farm.rooms = save_farm(&farm);
	// heat_map(farm, &rlist);
	// print_all_err();
	paint_rooms(farm.rooms);
	// paint_farm(list);
	free_list(&farm.rooms);
	// system("leaks lem-in");
	return (0);
}
