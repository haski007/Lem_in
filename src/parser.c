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

static int 					start_end(char *content)
{
	if (ft_strstr(content, "##start"))
		return (1);
	else if (ft_strstr(content, "##end"))
		return (2);
	return (0);
}

static t_room				*make_room(char *str, char rank)
{
	t_room	*room;
	int		i;

	i = 0;
	room = (t_room*)malloc(sizeof(t_room));
	room->name = ft_strdup(str);
	return (room);
}

t_list				*save_farm(t_farm *farm)
{
	t_list	*head;
	char	*line;
	int		rank;
	int		fd = 0;

	fd = open("easy_farm", O_RDONLY);
	head = NULL;
	get_next_line(fd, &line);
	if (!(farm->ants = ft_atoi(line)))
	{
		ft_putendl(strerror(5));
		exit(5);
	}
	ft_strdel(&line);
	while (get_next_line(fd, &line))
	{
		rank = 0;
		if (ft_strequ(line, "##start"))
		{
			rank = 1;
			ft_strdel(&line);
			get_next_line(fd, &line);
		}
		if (ft_strequ(line, "##end"))
		{
			rank = 2;
			ft_strdel(&line);
			get_next_line(fd, &line);
		}
		if (ft_strchr(line, '-'))
			rank = 2;
		else
			ft_lstadd(&head, ft_lstnew(make_room(line, rank), sizeof(t_room)));
		ft_strdel(&line);
	}
	return (head);
}