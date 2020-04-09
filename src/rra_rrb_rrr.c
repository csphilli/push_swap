/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 10:12:03 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/09 14:37:25 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stacks *stacks, int nbr)
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
		stacks->moves_a--;
		if (nbr == 0)
			printf("rra - nbr_moves:%d\n", stacks->nbr_moves);
	}
}

void	rrb(t_stacks *stacks, int nbr)
{
	t_lists *tail;
	t_lists *tail_minus_one;

	tail = stacks->head_b;
	tail_minus_one = tail;
	if (stacks && stacks->head_b->next != NULL)
	{
		while (tail_minus_one->next->next != NULL)
			tail_minus_one = tail_minus_one->next;
		tail = tail_minus_one;
		tail = tail->next;
		tail->next = stacks->head_b;
		tail_minus_one->next = NULL;
		stacks->head_b = tail;
		stacks->nbr_moves++;
		stacks->moves_b--;
		if (nbr == 0)
			printf("rrb - nbr_moves:%d\n", stacks->nbr_moves);		
	}
}

void	rrr(t_stacks *stacks, int nbr)
{
	rra(stacks, nbr);
	rrb(stacks, nbr);
	stacks->nbr_moves--;
	printf("rrr - nbr_moves:%d\n", stacks->nbr_moves);
}
