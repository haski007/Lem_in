/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:36:24 by pdemian           #+#    #+#             */
/*   Updated: 2019/07/16 21:36:26 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char		*make_step(int ant, char *name)
{
	char	*str;
	char	*tmp;
	char	*tmp2;

	str = ft_strdup("L");
	tmp = ft_strjoin(str, tmp2 = ft_itoa(ant));
	free(tmp2);
	free(str);
	str = ft_strjoin(tmp, "-");
	free(tmp);
	tmp = ft_strjoin(str, name);
	free(str);
	return (tmp);
}

t_ant		*make_ant(t_room *room, int N, int i)
{
	t_ant *ant;

	ant = (t_ant*)malloc(sizeof(t_ant));
	ant->N = N;
	ant->room = room;
	ant->row = i;
	return (ant);
}

int			start(t_farm *farm, t_list **queue, t_list **paths)
{
	t_list 	*path;
	t_ant	*ant;
	int		i;
	static int		n = 0;

	i = 0;
	path = *paths;
	while (path && farm->ants)
	{
		if (!valid_path(farm, (t_list*)path->content))
			break ;
		farm->ants--;
		ft_lstadd(queue, ft_lstnew(ant = make_ant(*(t_room**)((t_list*)path->content)->content, ++n, ++i), sizeof(t_ant)));
		path = path->next;
	}
	return (1);
}

int			move_ant(t_farm *farm, t_list **queue, t_ant *ant, t_list *path)
{
	t_list	*list;

	list = path;
	while (list)
	{
		if (ft_strequ((*(t_room**)list->content)->name, ant->room->name))
		{
			if (ant->room->rank == 2)
			{
				printf("L%d-%s ", ant->N, ant->room->name);
				ft_lstdelast(queue);
				return (1);
			}
			else
			{
				printf("L%d-%s ", ant->N, ant->room->name);
				ft_lstadd(queue, ft_lstnew(make_ant(*(t_room**)list->next->content, ant->N, ant->row), sizeof(t_ant)));
				ft_lstdelast(queue);
				return (0);
			}
		}
		list = list->next;
	}
	return (0);
}

void 		movement(t_farm *farm)
{
	t_list	*queue;
	t_list	*paths;
	t_list	*tmp;
	int		fuck;
	int		i;
	int		end;
	int		n;

	n = 0;
	end = farm->ants;
	queue = NULL;
	while (end > 0)
	{
		paths = farm->path;
		start(farm, &queue, &paths);
		system("leaks lem-in");
		exit(0);
		tmp = queue;
		fuck = ((t_ant*)queue->content)->N;
		while (tmp)
		{
			while (tmp->next)
				tmp = tmp->next;
			i = 0;
			paths = farm->path; 
			while (++i < ((t_ant*)tmp->content)->row)
				paths = paths->next;
			i = end;
			end -= move_ant(farm, &queue, (t_ant*)tmp->content, (t_list*)paths->content);
			tmp = queue;
			if (!tmp || (((t_ant*)queue->content)->N == fuck && end == i))
				break ;
		}
		printf("\n");
		n++;
	}
	printf("---------------------------------------\nNumber of lines = %d\n---------------------------------------\n", n);
}