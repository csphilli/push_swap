/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_and_6_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 17:47:11 by csphilli          #+#    #+#             */
/*   Updated: 2020/06/15 13:44:08 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_tail_nbr_b(t_stacks *stacks)
{
	t_lists *tail_b;

	if (stacks->head_b != NULL)
	{
		tail_b = stacks->head_b;
		while (tail_b->next != NULL)
			tail_b = tail_b->next;
		return (tail_b->nbr);
	}
	return (0);
}

static void	to_b_56_part_2(t_stacks *stacks)
{
	t_lists *b;
	t_lists	*a;
	int		tail_nbr;

	b = stacks->head_b;
	a = stacks->head_a;
	if (b && b->next != NULL)
	{
		tail_nbr = get_tail_nbr_b(stacks);
		if (b->nbr < tail_nbr)
			rb(stacks, 0);
		else if (b->nbr < b->next->nbr)
			sb(stacks, 0);
	}
}

static void	push_to_b_56(t_stacks *stacks)
{
	t_lists *a;
	t_lists *b;

	a = stacks->head_a;
	b = stacks->head_b;
	init_min_max(stacks);
	min_max_a(stacks);
	stacks->ll_a_cur = stacks->ll_a_start;
	while (stacks->ll_a_cur > 2)
	{
		a = stacks->head_a;
		if (a->nbr == stacks->a_min || a->nbr == stacks->a_max)
			ra(stacks, 0);
		else
			pb(stacks, 0);
		to_b_56_part_2(stacks);
	}
}

static void	push_to_a_56(t_stacks *stacks)
{
	t_lists *a;
	t_lists *b;

	a = stacks->head_a;
	b = stacks->head_b;
	while (stacks->ll_b_cur > 0)
	{
		b = stacks->head_b;
		if (b->next && b->nbr < b->next->nbr)
			sb(stacks, 0);
		else
			pa(stacks, 0);
	}
}

void		sort_5_and_6(t_stacks *stacks)
{
	push_to_b_56(stacks);
	if (stacks->head_a->nbr < stacks->head_a->next->nbr)
		ra(stacks, 0);
	push_to_a_56(stacks);
	rra(stacks, 0);
}
