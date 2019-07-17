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

void						count_distanse(t_list **alst)
{
	t_list	*path;
	t_list	*list;
	t_room	*room;
	int		len;

	path = *alst;
	while (path)
	{
		list = (t_list*)path->content;
		len = 0;
		while (list)
		{
			len++;
			list = list->next;
		}
		list = (t_list*)path->content;
		room = *(t_room**)list->content;
		room->lenght = len;
		path = path->next;
	}
}

static int 					start_end(char *content)
{
	if (ft_strstr(content, "##start"))
		return (1);
	else if (ft_strstr(content, "##end"))
		return (2);
	return (0);
}

static void					get_links(char *line, t_list **alst)
{
	t_list		*list;
	t_room		*room;
	t_room		*a;
	t_room		*b;
	int			i;

	i = 0;
	while (line[i] != '-')
		i++;
	list = *alst;
	while (list)
	{
		room = list->content;
		if (ft_strnequ(line, room->name, i))
			a = room;
		else if (ft_strequ(line + i + 1, room->name))
			b = room;
		list = list->next;
	}
	ft_lstadd(&a->tubes, ft_lstnew(&b, sizeof(t_room*)));
	ft_lstadd(&b->tubes, ft_lstnew(&a, sizeof(t_room*)));
}

static t_room				*make_room(char *str, char rank)
{
	t_room	*room;
	int		i;

	i = 0;
	room = (t_room*)malloc(sizeof(t_room));
	while (str[i] != ' ')
		i++;
	room->name = ft_strndup(str, i);
	room->x = ft_atoi(str + i);
	i++;
	room->tubes = NULL;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	room->y = ft_atoi(str + i);
	room->rank = rank;
	// room->value = (rank == 2) ? 0 : -1;
	room->ant = -1;
	if (rank == 1)
		room->busy = 1;
	else
		room->busy = 0;
	room->busy2 = 0;
	return (room);
}

t_list				*save_farm(t_farm *farm)
{
	t_list	*head;
	t_room	*room;
	char	*line;
	int		rank;
	int		fd = 0;

	// fd = open("ten_farm", O_RDONLY);
	head = NULL;
	while (get_next_line(fd, &line))
	{
		rank = 0;
		while (line[0] == '#' || !farm->ants)
		{
			farm->ants = (!farm->ants) ? ft_atoi(line) : farm->ants;
			rank = start_end(line);
			ft_strdel(&line);
			if (!get_next_line(fd, &line))
				return (head);
		}
		if (ft_strchr(line, '-'))
			get_links(line, &head);
		else
		{
			ft_lstadd(&head, ft_lstnew(room = make_room(line, rank), sizeof(t_room)));
			free(room);
		}
		ft_strdel(&line);
	}
	return (head);
}