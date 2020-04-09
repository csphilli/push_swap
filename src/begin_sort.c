/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 14:41:13 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/09 13:40:47 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	begin_sort(t_stacks *stacks)
{
	check_full_sort(stacks);
	if (stacks->full_sort == false)
	{
		if (stacks->ll_a_start == 2)
			sort_two_numbers(stacks);
		else if (stacks->ll_a_start == 3)
			sort_three_numbers(stacks);	
		else
		{
			sort_a_to_b(stacks);
			sort_three_numbers(stacks);
			the_big_sort(stacks);
		}
		check_full_sort(stacks);
	}
}
