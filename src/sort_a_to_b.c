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

static void	push_to_b_part_two(t_stacks *stacks)
{
	t_lists *a;

	while (stacks->ll_a_cur > 3)
	{
		a = stacks->head_a;
		if (a->nbr == stacks->a_max || a->nbr == stacks->a_min)
			exec_parse(stacks, "ra");
		else
			exec_parse(stacks, "pb");
	}
}

void		sort_a_to_b(t_stacks *stacks)
{
	int		median;
	t_lists *a;

	a = stacks->head_a;
	median = find_median(stacks->head_a);
	init_min_max(stacks);
	min_max_a(stacks);
	stacks->ll_a_cur = stacks->ll_a_start;
	// printf("ll_a_cur: %d | start: %d\n", stacks->ll_a_cur, stacks->ll_a_start);
	// printf("median: %d\n", median);
	while (stacks->ll_a_cur > stacks->ll_a_start / 2)
	{
		a = stacks->head_a;
		if ((a->nbr != stacks->a_max) && (a->nbr != stacks->a_min)
			&& (a->nbr <= median))
			exec_parse(stacks, "pb");
		else
			exec_parse(stacks, "ra");
	}
	push_to_b_part_two(stacks);
}
