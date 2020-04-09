/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 10:38:00 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/06 19:31:38 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// static void	min_max_a(t_stacks *stacks)
// {
// 	if (stacks->head_a)
// 	{
// 		t_lists *a;
// 		int		index;

// 		index = 0;
// 		a = stacks->head_a;
// 		stacks->a_max = a->nbr;
// 		stacks->a_min = a->nbr;
// 		while (a != NULL)
// 		{
// 			if (a->nbr >= stacks->a_max)
// 			{
// 				stacks->a_max = a->nbr;
// 				stacks->pos_a_max = index;
// 			}
// 			if (a->nbr <= stacks->a_min)
// 			{
// 				stacks->a_min = a->nbr;
// 				stacks->pos_a_min = index;
// 			}
// 			index++;
// 			a = a->next;
// 		}
// 	}
// }

static int	mp(t_stacks *stacks)
{
	int	midpoint;

	midpoint = 1;
	midpoint = stacks->ll_a_cur / 2;
	midpoint += midpoint % 2 == 1 ? 1 : 0;
	return (midpoint);
}

static int		calc_move(t_stacks *stacks)
{
	int		midpoint;
	int		to_move;

	to_move = 0;
	// stacks->ll_a_cur = stacks->ll_a_start;
	midpoint = mp(stacks);
	min_max_a(stacks);
	// print_min_max_lists(stacks);
	if (stacks->pos_a_min > midpoint)
		to_move = stacks->ll_a_cur - stacks->pos_a_min;
	else if (stacks->pos_a_min <= midpoint)
		to_move = stacks->pos_a_min;
	// printf("ll_a_cur:%d\n", stacks->ll_a_cur);
	// printf("ll_a_start:%d\n", stacks->ll_a_start);
	// printf("midpoint:%d\n", midpoint);
	// printf("pos_a_min:%d | pos_a_max:%d\n", stacks->pos_a_min, stacks->pos_a_max);
	// printf("to_move:%d\n", to_move);
	return (to_move);

	
}



void	do_a(t_stacks *stacks)
{
	int		to_move;
	int		midpoint;

	to_move = 0;
	midpoint = 0;
	stacks->ll_a_cur = stacks->ll_a_start;
	while (stacks->ll_a_cur > 3)
	{
		// printf("LIST A\n");
		// display_list(stacks->head_a);
		midpoint = mp(stacks);
		to_move = calc_move(stacks);
		if (stacks->head_a->nbr == stacks->a_max)
			ra(stacks);
		else if (stacks->pos_a_min > midpoint)
		{
			while (to_move-- > 0)
				rra(stacks);
			pb(stacks);
		}
		else if (stacks->pos_a_min <= midpoint)
		{
			while (to_move-- > 0)
				ra(stacks);
			pb(stacks);
		}
		// printf("LIST B\n");
		// display_list(stacks->head_b);
		// printf("head_a->nbr:%d\n", stacks->head_a->nbr);
		
	}
}