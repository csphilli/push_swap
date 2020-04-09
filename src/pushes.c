/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 14:27:07 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/09 14:27:37 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		push_a(t_stacks *stacks, int nbr)
{
	t_lists *tmp;
	t_lists *node;

	node = create_new_node(nbr);
	tmp = stacks->head_a;
	if (stacks && node)
	{
		if (!stacks->head_a)
			stacks->head_a = node;
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = node;
		}
	}
}

void		push_b(t_stacks *stacks, int nbr)
{
	t_lists *tmp;
	t_lists *node;

	node = create_new_node(nbr);
	tmp = stacks->head_b;
	if (stacks && node)
	{
		if (!stacks->head_b)
			stacks->head_b = node;
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = node;
		}
	}
}