/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 19:26:36 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/13 15:29:59 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	These functions handle the moving from stack b to a. The amount of moves
**	are stored in the struct as moves_a and moves_b. For the doubles moves,
**	obviously the move can only be done as much as the lowest value of moves
**	a or b. So it'll do the double up until that either value is zero. Then
**	the remaining moves will be carried out by the single move functions.
**	Which direction is stored in the struct as dir_a and dir_b. 1 means
**	a standard rotation (ra/rb) and 0 is the reverse rotations. There are
**	four different combinations possible hence the need for four different
**	if else statements. Again, function line limit count.. smdh
*/

static void	sort_b_to_a_next(t_stacks *stacks)
{
	if (stacks->dir_a == 0 && stacks->dir_b == 1)
	{
		while (stacks->moves_a > 0)
			rra(stacks, 0);
		while (stacks->moves_b > 0)
			rb(stacks, 0);
	}
	else if (stacks->dir_a == 0 && stacks->dir_b == 0)
	{
		while (stacks->moves_a > 0 && stacks->moves_b > 0)
			rrr(stacks, 0);
		while (stacks->moves_a > 0)
			rra(stacks, 0);
		while (stacks->moves_b > 0)
			rrb(stacks, 0);
	}
	pa(stacks, 0);
}

void	sort_b_to_a(t_stacks *stacks)
{
	if (stacks->dir_a == 1 && stacks->dir_b == 1)
	{
		while (stacks->moves_a > 0 && stacks->moves_b > 0)
			rr(stacks, 0);
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
