/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 19:26:36 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/09 12:54:18 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_b_to_a_next(t_stacks *stacks)
{
	if (stacks->dir_a == 0 && stacks->dir_b == 1)
	{
		while (stacks->moves_a > 0)
			rra(stacks, 1);
		while (stacks->moves_b > 0)
			rb(stacks, 0);
	}
	else if (stacks->dir_a == 0 && stacks->dir_b == 0)
	{
		while (stacks->moves_a > 0 && stacks->moves_b > 0)
			rrr(stacks, 1);
		while (stacks->moves_a > 0)
			rra(stacks, 0);
		while (stacks->moves_b > 0)
			rrb(stacks, 0);
	}
	pa(stacks);
}

void	sort_b_to_a(t_stacks *stacks)
{
	if (stacks->dir_a == 1 && stacks->dir_b == 1)
	{
		while (stacks->moves_a > 0 && stacks->moves_b > 0)
			rr(stacks, 1);
		while (stacks->moves_a > 0)
			ra(stacks, 0);
		while (stacks->moves_b > 0)
			rb(stacks, 0);
	}
	else if (stacks->dir_a == 1 && stacks->dir_b == 0)
	{
		while (stacks->moves_a > 0)
			ra(stacks, 0);
		while (stacks->moves_b > 0)
			rrb(stacks, 0);
	}
	sort_b_to_a_next(stacks);
}