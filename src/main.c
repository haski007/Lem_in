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
// #include "parser.c"
// #include "../libft/get_next_line.c"
// #include "../libft/ft_strlen.c"
// #include "../libft/ft_lstnew.c"
// #include "../libft/ft_strchr.c"
// #include "../libft/ft_strdup.c"
// #include "../libft/ft_strcpy.c"
// #include "../libft/ft_strequ.c"
// #include "../libft/ft_atoi.c"
// #include "../libft/ft_putnbr.c"
// #include "../libft/ft_putendl.c"
// #include "../libft/ft_strcmp.c"
// #include "../libft/ft_strcdup.c"
// #include "../libft/ft_strdel.c"
// #include "../libft/ft_strstr.c"
// #include "../libft/ft_strjoin.c"
// #include "../libft/ft_strndup.c"
// #include "../libft/ft_strnew.c"
// #include "../libft/ft_putchar.c"
// #include "../libft/ft_memcpy.c"
// #include "../libft/ft_lstadd.c"
// #include "../libft/ft_memalloc.c"
// #include "../libft/ft_bzero.c"
// #include "../libft/ft_strcat.c"
// #include "../libft/ft_memset.c"

static void		print_all_err(void)
{
	int	i;

	i = -1;
	while (++i < 107)
		printf("%d) %s\n", i, strerror(i));
}

void			paint_farm(t_list *list)
{
	while (list)
	{
		printf("%zu) ", list->content_size);
		printf("%s", list->content);
		list = list->next;
	}
}

void			paint_rooms(t_rlist *rlist)
{
	while (rlist)
	{
		printf("%s %d %d | rank = %d\n", NAME, rlist->room->x, rlist->room->y, rlist->room->rank);
		rlist = rlist->next;
	}
}



static void		free_lists(t_list **alist, t_rlist **arlist)
{
	t_list	*list;
	t_list	*tmp;

	list = *alist;
	while (list)
	{
		tmp = list->next;
		ft_strdel(&list->content);
		free(list);
		list = tmp;
	}
	*alist = NULL;
}

int				main(void)
{
	t_farm	farm;
	t_rlist	*rlist;
	t_list	*list;

	list = save_farm(&farm);
	rlist = get_rooms(list);
	// print_all_err();
	// paint_rooms(rlist);
	// paint_farm(list);
	free_lists(&list, &rlist);
	// system("leaks lem-in");
	return (0);
}
