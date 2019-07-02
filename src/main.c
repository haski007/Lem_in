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

void		paint_rooms(t_rlist *rlist)
{
	while (rlist)
	{
		printf("%s %d %d | rank = %d\n", rlist->room->name, rlist->room->x, rlist->room->y, rlist->room->rank);
		rlist = rlist->next;
	}
}

int			main(void)
{
	t_farm	farm;
	t_rlist	*rlist;
	t_list	*list;

	list = save_farm(&farm);
	rlist = get_rooms(list);
	// print_all_err();
	paint_rooms(rlist);
	// paint_farm(list);
	return (0);
}
