/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:01:24 by pdemian           #+#    #+#             */
/*   Updated: 2019/07/16 18:01:26 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int			valid_path(t_farm *farm, t_list *path)
{
	t_list	*list;
	t_list	*paths;
	t_list	*list2;
	int 	res;

	res = 0;
	list = path;
	paths = farm->path;
	list2 = (t_list*)paths->content;
	while (!ft_strequ((*(t_room**)list2->content)->name, (*(t_room**)list->content)->name))
	{
		res += (*(t_room**)list->content)->lenght - (*(t_room**)list2->content)->lenght;
		paths = paths->next;
		list2 = (t_list*)paths->content;
	}
	return ((res < farm->ants) ? 1 : 0);
}

void            cut_the_path(t_farm *farm)
{
    t_list  *path;

    path = farm->path;
	while (path)
	{
		if (!valid_path(farm, (t_list*)path->content))
		{
			while (path)
				ft_lstdelast(&path);
			path = farm->path;
			while (path->next->next)
				path = path->next;
			path->next = NULL;
			break ;
		}
		path = path->next;
	}
}