/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 21:53:56 by pdemian           #+#    #+#             */
/*   Updated: 2019/06/28 16:27:49 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# include "../libft/includes/libft.h"

# define CONT list->content
# define NAME rlist->room->name
# define VALUE rlist->room->value
# define LLIST rlist->room->llist
# define TUBE rlist->room->llist->tube
# define NEXT_LLIST rlist->room->llist->next

typedef struct 		s_farm
{
	int				ants;
} 					t_farm;

typedef struct		s_llist
{
	char			*tube;
	struct s_llist	*next;
}					t_llist;

typedef struct		s_room
{
	char			*name;
	char			rank;
	t_llist			*llist;
	int				x;
	int				y;
	int				value;
}					t_room;

typedef struct 		s_rlist
{
	t_room			*room;
	struct s_rlist	*next;
}					t_rlist;

t_list				*save_farm(t_farm *farm);
t_rlist				*get_rooms(t_list *list);



void				paint_farm(t_list *list);
void				paint_rooms(t_rlist *rlist);

#endif