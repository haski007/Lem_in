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

int				parse_farm(t_farm *farm)
{
	char	*line;

	get_next_line(0, &line);
	farm->ants = ft_atoi(line);
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "start")
			
	}
}