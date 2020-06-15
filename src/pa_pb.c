/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:50:28 by csphilli          #+#    #+#             */
/*   Updated: 2020/06/15 13:37:15 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Allowed functions to help sort the list. The toggle is used
**	for the printing of the instructions. push_swap prints the
**	instructions, and checker does not.
*/

void	pa(t_stacks *stacks, int toggle)
{
	unshift_a(stacks, stacks->head_b->nbr);
	pop_b(stacks);
	stacks->ll_b_cur--;
	stacks->ll_a_cur++;
	if (toggle == 0)
		ft_putendl("pa");
}

void	pb(t_stacks *stacks, int toggle)
{
	unshift_b(stacks, stacks->head_a->nbr);
	pop_a(stacks);
	stacks->ll_b_cur++;
	stacks->ll_a_cur--;
	if (toggle == 0)
		ft_putendl("pb");
}

/*
**	Push_a is simply used to populate stack_a in the beginning.
*/

void	push_a(t_stacks *stacks, int nbr)
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
