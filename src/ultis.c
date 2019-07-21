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

int			show_error(const char *error)
{
	ft_printf("%t%s%t\n", B_RED, error, EOC);
	exit(0);
}

int			valid_path(t_farm *farm, t_list *path)
{
	t_list	*list;
	t_list	*paths;
	t_list	*list2;
	int		res;

	res = 0;
	list = path;
	paths = farm->path;
	list2 = (t_list*)paths->content;
	while (!ft_strequ((*(t_room**)list2->content)->name,
	(*(t_room**)list->content)->name))
	{
		res += (*(t_room**)list->content)->lenght -
		(*(t_room**)list2->content)->lenght;
		paths = paths->next;
		list2 = (t_list*)paths->content;
	}
	return ((res < farm->ants) ? 1 : 0);
}

void		print_move(t_farm *farm, t_ant *ant, t_room *room)
{
	void		*color;

	if (!farm->flags.c)
		color = EOC;
	else if (ant->N % 6 == 0)
		color = B_BLUE;
	else if (ant->N % 6 == 1)
		color = B_CYAN;
	else if (ant->N % 6 == 2)
		color = B_GREEN;
	else if (ant->N % 6 == 3)
		color = B_MAGENTA;
	else if (ant->N % 6 == 4)
		color = B_RED;
	else if (ant->N % 6 == 5)
		color = B_YELLOW;
	if (!farm->flags.c && !farm->flags.s && ant->room->rank != 1)
		ft_printf("L%d-%s ", ant->N, room->name);
	else if ((room->rank == 2 ||
	room->rank == 2) && !farm->flags.s && ant->room->rank != 1)
		ft_printf("%tL%d-%s %t", B_WHITE, ant->N, room->name, EOC);
	else if (!farm->flags.s && ant->room->rank != 1)
		ft_printf("%tL%d-%s %t", color, ant->N, room->name, EOC);
}

void		print_usage(void)
{
	ft_printf("usage: ./lem-in [-pcsrh] < map\n");
	ft_printf("       -h    help     - show usage.\n");
	ft_printf("       -p    paths    - show all possible paths.\n");
	ft_printf("       -c    color 	 - paint everything in colors\n");
	ft_printf("       -s    silence  - dont show madatory part\n");
	ft_printf("       -r    result   - show result and goal\n");
	ft_printf("       -l    leaks    - useless bonus shows leaks\n");
	exit(0);
}

void		*rand_color(void)
{
	int		random;

	random = rand() % 6;
	if (random % 6 == 0)
		return (B_YELLOW);
	else if (random % 6 == 1)
		return (B_GREEN);
	else if (random % 6 == 2)
		return (B_MAGENTA);
	else if (random % 6 == 3)
		return (B_RED);
	else if (random % 6 == 4)
		return (B_BLUE);
	else if (random % 6 == 5)
		return (B_CYAN);
	return (0);
}
