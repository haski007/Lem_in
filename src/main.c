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

void			paint_path(t_list *path)
{
	t_list	*list;
	t_room	*room;
	void	*color;
	int		len;
	int		i;

	len = 0;
	i = 0;
	color = rand_color();
	list = path;
	while (list)
	{
		room = *(t_room**)list->content;
		++i;
		ft_printf("%t%s", color, room->name);
		if (list->next)
			ft_printf("--->%t", EOC);
		else
			ft_printf("%t", EOC);
		list = list->next;
	}
}

void			paint_paths(t_farm *farm)
{
	t_list		*list;
	int			i;

	i = 0;
	list = farm->path;
	while (list)
	{
		++i;
		if (i != 1)
		{
			ft_putchar('\n');
			ft_putchar('\n');
		}
		ft_printf("%t%2d) lenght: %d | %t", B_CYAN, i,
		(*(t_room**)((t_list*)list->content)->content)->lenght, EOC);
		paint_path((t_list*)list->content);
		list = list->next;
	}
	ft_putchar('\n');
	ft_putchar('\n');
}

void			get_flags(t_farm *farm, int ac, char **av)
{
	int			i;
	int			j;
	const char	*my_flags;

	my_flags = "pcsrl";
	if (ac == 1)
		return ;
	ft_bzero(&farm->flags, sizeof(t_flags));
	i = 0;
	while (++i < ac)
	{
		if (av[i][0] != '-')
			print_usage();
		j = 0;
		while (av[i][++j])
		{
			if (!ft_strchr(my_flags, av[i][j]))
				print_usage();
			farm->flags.p = (av[i][j] == 'p') ? 1 : farm->flags.p;
			farm->flags.c = (av[i][j] == 'c') ? 1 : farm->flags.c;
			farm->flags.s = (av[i][j] == 's') ? 1 : farm->flags.s;
			farm->flags.r = (av[i][j] == 'r') ? 1 : farm->flags.r;
			farm->flags.l = (av[i][j] == 'l') ? 1 : farm->flags.l;
		}
	}
}

void			print_input(t_farm *farm)
{
	t_list	*list;

	list = farm->input;
	validator(farm);
	while (list)
	{
		if (ft_strnequ((char*)list->content,
		"#Here is the number of lines required:", 38))
			farm->num_lines = ft_atoi((char*)list->content + 38);
		if (!farm->flags.s && farm->flags.c)
			ft_printf("%t%s\n%t", B_GREEN,
			(char*)list->content, EOC);
		else if (!farm->flags.s)
			ft_putendl((char*)list->content);
		list = list->next;
	}
	ft_putchar('\n');
}

int				main(int ac, char **av)
{
	t_farm	farm;

	srand(time(NULL));
	farm.res = 0;
	farm.ants = 199191;
	farm.input = NULL;
	get_flags(&farm, ac, av);
	farm.rooms = save_farm(&farm);
	print_input(&farm);
	get_paths(&farm);
	if (farm.flags.p)
		paint_paths(&farm);
	movement(&farm);
	if (farm.flags.r)
	{
		ft_printf("%t |\n\\ /\nNumber of lines = %t%d\n/ \\\n |\n%t",
		B_GREEN, B_YELLOW, farm.res, EOC);
		ft_printf("%tHere is the number of lines required: %t%d\n%t",
		B_MAGENTA, B_YELLOW, farm.num_lines, EOC);
	}
	if (farm.flags.l)
		system("leaks lem-in");
	return (0);
}
