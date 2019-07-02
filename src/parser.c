/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 21:46:09 by pdemian           #+#    #+#             */
/*   Updated: 2019/06/28 21:46:10 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void				make_room(t_room *room, char **arr, int i)
{
	room->name = arr[0];
	room->x = ft_atoi(arr[1]);
	room->y = ft_atoi(arr[2]);
	room->rank = i;
	free(arr[0]);
	free(arr[1]);
	free(arr[2]);
	free(arr);
}

static t_rlist				*newrlst(t_room *room)
{
	t_rlist		*list;

	list = (t_rlist*)malloc(sizeof(t_rlist));
	list->room = room;
	list->next = NULL;
	return (list);
}

t_rlist				*get_rooms(t_list *list)
{
	t_rlist		*rlist;
	t_room		room;
	char		**arr;
	int			i;
	
	i = 0;
	rlist = NULL;
	while (list)
	{
		if (list->content[0] != '#' && !ft_strchr(list->content, '-'))
		{
			arr = ft_strsplit(list->content, ' ');
			if (!rlist)
			{
				make_room(&room, arr, i);
				rlist = newrlst(&room);
				printf("%s\n", rlist->room->name);
				rlist = rlist->next;
			}
		}
		list = list->next;
	}
	return (rlist);
}

t_list				*save_farm(t_farm *farm)
{
	char	*line;
	t_list	*head;
	t_list	*tmp;
	t_list	*p;

	head = NULL;
	tmp = NULL;
	get_next_line(0, &line);
	if (!(farm->ants = ft_atoi(line)))
		ft_putstr(strerror(5));
	while (get_next_line(0, &line))
	{
		if (!head)
		{
			head = ft_lstnew(line, ft_strlen(line));
			p = head;
		}
		else
		{
			tmp = ft_lstnew(line, ft_strlen(line));
			p->next = tmp;
			p = tmp;
		}
	}
	return (head);
}