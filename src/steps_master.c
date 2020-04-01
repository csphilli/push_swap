/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_master.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 14:41:13 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/01 15:18:58 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	begin_sort(t_stacks *stacks)
{
	// printf("BEGIN SORT\n");
	first_step(stacks); // sorting correctly.
	check_order(stacks);
	if (stacks->sorted == true)
	{
		display_list(stacks->head_a);
		display_list(stacks->head_b);
		exit(-1);
	}
    // stacks->head_a = first_step(stacks, stacks->head_a); // sorting correctly.
	// printf("2nd STEP\n");
	second_step(stacks); // sorting correctly!
	third_step(stacks);
	fourth_step(stacks);
	fifth_step(stacks);
	// stacks = second_step(stacks); // sorting correctly!
}
