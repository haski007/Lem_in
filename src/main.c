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

void			paint_rooms(t_rlist *rlist)
{
	while (rlist)
	{
		// printf("%10s value = %d     | %s:\n", RNAME, RVALUE,  (rlist->room->rank == 2) ? "end" : NULL);
		printf("%s     | rank = %d:\n", RNAME, rlist->room->rank);
		paint_links(RLLIST);
		rlist = rlist->next;
	}
}

void			paint_links(t_llist *llist)
{
	int		i;

	i = 0;
	while (llist)
	{
		printf("link %d%8s\n", ++i, llist->tube);
		llist = llist->next;
	}
}

static void		free_lists(t_list **alist, t_rlist **arlist)
{
	t_list	*list;
	t_list	*tmp;

	list = *alist;
	while (list)
	{
		tmp = list->next;
		ft_strdel(&list->content);
		free(list);
		list = tmp;
	}
	*alist = NULL;
}

int				main(void)
{
	t_farm	farm;
	t_rlist	*rlist;
	t_list	*list;

	list = save_farm(&farm);
	rlist = get_rooms(list);
	heat_map(&rlist);
	// print_all_err();
	paint_rooms(rlist);
	// paint_farm(list);
	free_lists(&list, &rlist);
	// system("leaks lem-in");
	return (0);
}
