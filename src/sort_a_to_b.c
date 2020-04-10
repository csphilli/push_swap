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
			// ft_putendl("ra");
			ra(stacks, 0);
		else
			// ft_putendl("pb");
			pb(stacks, 0);
	}
}

void		sort_a_to_b(t_stacks *stacks)
{
	int		median;
	t_lists *a;
	int i;
	// int		less_median;
	// int		size;

	// size = stacks->ll_a_start / 2 + 2;

	// less_median = count_below_median(stacks->head_a);

	i = 0;

	a = stacks->head_a;
	median = find_median(stacks->head_a);
	init_min_max(stacks);
	min_max_a(stacks);
	stacks->ll_a_cur = stacks->ll_a_start;
	// printf("ll_a_cur: %d | start: %d\n", stacks->ll_a_cur, stacks->ll_a_start);
	// printf("stacks->ll_a_c/2: %d\n", stacks->ll_a_cur / 2);
	// printf("numbers below median: %d\n", less_median);
	// printf("median: %d\n", median);
	while (stacks->ll_a_cur > (stacks->ll_a_start / 2) + 2)
	{
		// printf("ll_a_cur: %d\n", stacks->ll_a_cur);
		a = stacks->head_a;
		if ((a->nbr != stacks->a_max) && (a->nbr != stacks->a_min)
			&& (a->nbr <= median))
			// ft_putendl("pb");
			// exec_parse(stacks, "pb");
			pb(stacks, 0);
		else
			// ft_putendl("ra");
			// exec_parse(stacks, "ra");
			ra(stacks, 0);
		// display_list(stacks->head_a);
		i++;
	}
	// display_list(stacks->head_b);
	push_to_b_part_two(stacks);
}
