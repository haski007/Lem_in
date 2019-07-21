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
# include <math.h>
# include <time.h>

# include "../libft/includes/libft.h"

# define TUBE (*(t_room**)tubes->content)

typedef struct		s_flags
{
	unsigned int	p : 1;
	unsigned int	c : 1;
	unsigned int	s : 1;
	unsigned int	r : 1;
	unsigned int	l : 1;
}					t_flags;

typedef struct 		s_farm
{
	int				ants;
	int				res;
	int				num_lines;
	t_list			*rooms;
	t_list			*path;
	t_list			*input;
	t_flags			flags;
} 					t_farm;

typedef struct		s_room
{
	char			*name;
	char			rank;
	int				lenght;
	int				ant;
	int				x;
	int				y;
	char			busy;
	char			busy2 : 1;
	struct s_room	*parent;
	t_list			*tubes;
}					t_room;

typedef	struct		s_ant
{
	int				N;
	int				row;
	t_room			*room;
}					t_ant;



t_list				*save_farm(t_farm *farm);
void				heat_map(t_farm *farm);
void       			get_paths(t_farm *farm);
void				movement(t_farm *farm);
void				count_distanse(t_list **alst);
int					valid_path(t_farm *farm, t_list *path);
void				print_usage(void);
int					show_error(const char *error);
void				validator(t_farm *farm);





/*
** Bonus functions
*/

void				print_move();
void				*rand_color();








void				paint_farm(t_list *list);
void				paint_rooms(t_list *rooms);
void				paint_links(t_list *tubes);
void				paint_path(t_list *path);
void				paint_apath(t_farm *farm);





#endif