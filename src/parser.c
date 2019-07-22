/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 21:46:09 by pdemian           #+#    #+#             */
/*   Updated: 2019/07/22 19:22:40 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			count_distanse(t_list **alst)
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

static int		start_end(t_farm *farm, char **line)
{
	int		rank;

	rank = 0;
	farm->ants = (farm->ants == 199191) ? ft_atoi(*line) : farm->ants;
	if (ft_strstr(*line, "##") && !ft_strequ(*line, "##start")
	&& !ft_strequ(*line, "##end"))
		show_error("Whrong comand after double sharp ##...");
	if (ft_strequ(*line, "##start"))
		rank = 1;
	else if (ft_strequ(*line, "##end"))
		rank = 2;
	(line[0][0] == '\0') ? show_error("Newline is in non valid place") : 0;
	ft_strdel(line);
	if (!get_next_line(0, line))
		return (-1);
	(line[0][0] == '\0') ? show_error("Newline is in non valid place") : 0;
	while (line[0][0] == '#' && (rank == 1 || rank == 2))
	{
		ft_strdel(line);
		if (!get_next_line(0, line))
			return (-1);
	}
	ft_lstpush(&farm->input, ft_lstnew(*line, ft_strlen(*line) + 1));
	return (rank);
}

static void		get_links(char *line, t_list **alst)
{
	t_list		*list;
	t_room		*room;
	t_room		*a;
	t_room		*b;
	int			i;

	i = 0;
	while (line[i] != '-')
		i++;
	a = NULL;
	b = NULL;
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
	if (!a || !b)
		show_error("Really!? You have linked non existing room...!");
	ft_lstadd(&a->tubes, ft_lstnew(&b, sizeof(t_room*)));
	ft_lstadd(&b->tubes, ft_lstnew(&a, sizeof(t_room*)));
}

static t_room	*make_room(char *str, char rank)
{
	t_room	*room;
	int		i;
	int		j;

	room = (t_room*)malloc(sizeof(t_room));
	i = -1;
	while (str[++i] != ' ' && str[i])
		j = i;
	while (str[++j])
		if ((str[j] < '0' || str[j] > '9') && str[j] != ' ')
			show_error("Some of your rooms are incorrect...!");
	room->name = ft_strndup(str, i);
	room->x = ft_atoi(str + i);
	i++;
	room->tubes = NULL;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	room->y = ft_atoi(str + i);
	room->rank = rank;
	room->ant = 0;
	room->busy = 0;
	if (rank == 1)
		room->busy = 1;
	room->busy2 = 0;
	return (room);
}

t_list			*save_farm(t_farm *farm)
{
	t_list	*head;
	t_room	*room;
	char	*line;
	int		rank;

	head = NULL;
	while (get_next_line(0, &line) > 0)
	{
		(line[0] == '\0') ? show_error("Newline is in non valid place") : 0;
		rank = 0;
		ft_lstpush(&farm->input, ft_lstnew(line, ft_strlen(line) + 1));
		while (line[0] == '#' || farm->ants == 199191)
			if ((rank = start_end(farm, &line)) < 0)
				return (head);
		if (ft_strchr(line, '-'))
			get_links(line, &head);
		else
		{
			ft_lstadd(&head,
			ft_lstnew(room = make_room(line, rank), sizeof(t_room)));
			free(room);
		}
		ft_strdel(&line);
	}
	return (head);
}
