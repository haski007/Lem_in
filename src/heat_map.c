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

static void			heat_this(char *tube, t_rlist **rlist, int value)
{
	t_rlist		*list;

	list = *rlist;
	while (list)
	{
		if (ft_strequ(NAME, tube))
			VALUE = value;
		list = list->next;
	}
}

void				heat_map(t_rlist **rlist)
{
    t_rlist		*list;
	t_llist		*llist;

	int			i;
	llist = LLIST;
	i = 1;
    list = *rlist;
	while (list)
	{
		if (list->room->rank == 2)
		{
			while (llist)
			{
				heat_this(llist->tube, rlist, i);
				llist = llist->next;
			}
		}
		else if (VALUE == i)
		{
			while (llist)
			{
				heat_this(llist->tube, rlist, i++);
				llist = llist->next;
			}
			i++;
		}
		list = list->next;
	}
}