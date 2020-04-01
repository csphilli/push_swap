/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 10:12:03 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/01 14:54:15 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stacks *stacks)
{
	t_lists *tail;
	t_lists *tail_minus_one;

	tail = stacks->head_a;
	tail_minus_one = tail;
	if (stacks && stacks->head_a->next != NULL)
	{
		while (tail_minus_one->next->next != NULL)
			tail_minus_one = tail_minus_one->next;
		tail = tail_minus_one;
		tail = tail->next;
		tail->next = stacks->head_a;
		tail_minus_one->next = NULL;
		stacks->head_a = tail;
		stacks->nbr_moves++;
	}
}

void	rrb(t_stacks *stacks)
{
	// printf("LIST B @ RRB START\n");
	// display_list(stacks->head_b);
	t_lists *tail;
	t_lists *tail_minus_one;

	tail = stacks->head_b;
	tail_minus_one = tail;
	if (stacks && stacks->head_b->next != NULL)
	{
		while (tail_minus_one->next->next != NULL)
		{
			// printf("looping?\n");
			tail_minus_one = tail_minus_one->next;
		}
		// printf("tail_minus_one->nbr:%d\n", tail_minus_one->nbr);
		tail = tail_minus_one;
		tail = tail->next;
		tail->next = stacks->head_b;
		tail_minus_one->next = NULL;
		stacks->head_b = tail;
		stacks->nbr_moves++;
	}
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
	stacks->nbr_moves--;
}