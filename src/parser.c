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

t_list				*save_farm(t_farm *farm)
{
	char	*line;
	t_list	*head;
	t_list	*tmp;
	t_list	*p;

	head = NULL;
	tmp = NULL;
	get_next_line(0, &line);
	farm->ants = ft_atoi(line);
	while (get_next_line(0, &line))
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
	}
	return (head);
}