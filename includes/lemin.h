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

# define ROOM (t_room*)rooms->content

typedef struct 		s_farm
{
	int				ants;
	t_list			*rooms;
} 					t_farm;

typedef struct		s_room
{
	char			*name;
	char			rank;
	int				x;
	int				y;
	t_list			*tubes;
	int				value;
}					t_room;

t_list				*save_farm(t_farm *farm);
// void				heat_map(t_farm farm, t_rlist **rlist);






void				paint_farm(t_list *list);
void				paint_rooms(t_list *rooms);
void				paint_links(t_list *tubes);



#endif