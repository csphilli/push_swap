/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unshifts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 14:18:23 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/13 16:03:01 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Unshifts are used for adding an element to another list via pa or pb.
*/

void	unshift_b(t_stacks *stacks, int nbr)
{
	t_lists	*node;

	node = create_new_node(nbr);
	if (stacks->head_a && node)
	{
		if (!stacks->head_b)
			stacks->head_b = node;
		else
		{
			node->next = stacks->head_b;
			stacks->head_b = node;
		}
	}
}

void	unshift_a(t_stacks *stacks, int nbr)
{
	t_lists	*node;

	node = create_new_node(nbr);
	if (stacks->head_b && node)
	{
		if (!stacks->head_a)
			stacks->head_a = node;
		else
		{
			node->next = stacks->head_a;
			stacks->head_a = node;
		}
	}
}
