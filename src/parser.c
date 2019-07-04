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

static t_llist				*get_links(char *name, t_list *list)
{
	t_llist	*head;
	t_llist	*tmp;
	t_llist	*p;

	head = NULL;
	tmp = NULL;
	p = NULL;
	while (list)
	{
		if (!head && ft_strchr(CONT, '-') && ft_strstr(CONT, name))
		{
			head = newllst(name, CONT);
			p = head;
		}
		else if (ft_strchr(CONT, '-') && ft_strstr(CONT, name))
		{
			tmp = newllst(name, CONT);
			p->next = tmp;
			p = tmp;
		}
		list = list->next;
	}
	return (head);
}

static t_room				*make_room(char *str, char rank, t_list *list)
{
	t_room	*room;
	int		i;

	i = 0;
	room = (t_room*)malloc(sizeof(t_room));
	while (str[i] != ' ')
		i++;
	room->name = ft_strndup(str, i);
	room->llist = get_links(room->name, list);
	room->x = ft_atoi(str + i);
	i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	room->y = ft_atoi(str + i);
	room->rank = rank;
	return (room);
}


t_rlist				*get_rooms(t_list *list)
{
	t_rlist		*head;
	t_rlist		*tmp;
	t_rlist		*p;
	int			i;
	
	head = NULL;
	while (list)
	{
		i = 0;
		if (ft_strchr(CONT, '-'))
			break ;
		if ((i = start_end(CONT)))
			list = list->next;
		if (!head && CONT[0] != '#')
		{
			head = newrlst(make_room(CONT, i, list));
			p = head;
		}
		else if (head && CONT[0] != '#')
		{
			tmp = newrlst(make_room(CONT, i, list));
			p->next = tmp;
			p = tmp;
		}
		list = list->next;
	}
	return (head);
}

t_list				*save_farm(t_farm *farm)
{
	char	*line;
	t_list	*head;
	t_list	*tmp;
	t_list	*p;
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
		ft_strdel(&line);
	}
	return (head);
}