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
# define NAME list->room->name
# define RNAME rlist->room->name
# define VALUE list->room->value
# define RVALUE rlist->room->value
# define LLIST list->room->llist
# define RLLIST rlist->room->llist
# define TUBE rlist->room->llist->tube

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
t_llist				*newllst(char *name, char *tube);
t_rlist				*newrlst(t_room *room);
void				heat_map(t_rlist **rlist);






void				paint_farm(t_list *list);
void				paint_rooms(t_rlist *rlist);
void				paint_links(t_llist *llist);

#endif