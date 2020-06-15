/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 14:41:13 by csphilli          #+#    #+#             */
/*   Updated: 2020/06/15 13:40:28 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Sorting parser.
*/

void	begin_sort(t_stacks *stacks)
{
	check_full_sort(stacks);
	if (stacks->full_sort == false)
	{
		if (stacks->ll_a_start == 1)
			exit(0);
		else if (stacks->ll_a_start == 2)
			sort_two_numbers(stacks);
		else if (stacks->ll_a_start == 3)
			sort_three_numbers(stacks);
		else if (stacks->ll_a_start == 5 || stacks->ll_a_start == 6)
			sort_5_and_6(stacks);
		else
		{
			sort_a_to_b(stacks);
			sort_three_numbers(stacks);
			the_big_sort(stacks);
		}
		check_full_sort(stacks);
	}
}
