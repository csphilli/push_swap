/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:10:20 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/07 15:14:19 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Sorting from A to B. First finds the min and max value. Those values
**	are protected and not moved to stack b. Then it finds the MEDIAN value.
**	This is done to cut the list properly in half. If you just assumed that
**	the middle was max_value / 2, you'd run into chances of infinate looping
**	due to the majority of the stack being higher than the midpoint which would
**	result in the list not being put to b up until the midpoint. Also, notice
**	that the loop is: while (stacks->ll_a_cur > (stacks->ll_a_start / 2) + 2);
**	This extra two is to account for the min and max values that are protected
**	and shouldn't be considered in the length of the list. Also, don't you wish
**	we didn't have the lame function line limit count?! Far more elegant and
**	less clutter if we didn't...
*/

static void	push_to_b_part_two(t_stacks *stacks)
{
	t_lists *a;

	while (stacks->ll_a_cur > 3)
	{
		a = stacks->head_a;
		if (a->nbr == stacks->a_max || a->nbr == stacks->a_min)
			ra(stacks, 0);
		else
			pb(stacks, 0);
	}
}

void		sort_a_to_b(t_stacks *stacks)
{
	int		median;
	t_lists *a;
	int 	i;

	i = 0;
	a = stacks->head_a;
	median = find_median(stacks->head_a);
	init_min_max(stacks);
	min_max_a(stacks);
	stacks->ll_a_cur = stacks->ll_a_start;
	while (stacks->ll_a_cur > (stacks->ll_a_start / 2) + 2)
	{
		a = stacks->head_a;
		if ((a->nbr != stacks->a_max) && (a->nbr != stacks->a_min)
			&& (a->nbr <= median))
			pb(stacks, 0);
		else
			ra(stacks, 0);
		i++;
	}
	push_to_b_part_two(stacks);
}
