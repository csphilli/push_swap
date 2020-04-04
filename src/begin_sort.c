/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 14:41:13 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/04 13:11:37 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	begin_sort(t_stacks *stacks)
{
	// printf("BEGIN SORT\n");
	// printf("nbr_moves START:%d\n", stacks->nbr_moves);
	if (stacks->head_a != NULL)
	{
		scan_for_min_max_a(stacks);
		check_order_a(stacks);
	}
	if (stacks->head_b != NULL)
		scan_for_min_max_b(stacks);
	check_full_sort(stacks);
	if (stacks->full_sort == true)
		printf("FULLY SORTED\n");
	else
		printf("NOT FULLY SORTED\n");
	print_min_max_lists(stacks);
	// check_order_a_v1(stacks);

	// NEED A CHECK FOR LIST LEN HERE THAT THEN DIRECTS THE PROGRAM
	// TO THE CORRECT SORTING ALGO.

	if (stacks->sorted == false)
	{
		if (stacks->list_a_len_start < 4)
			sort_short(stacks);
	}
/*
	if (stacks->sorted == false)
	{
		printf("ENTERING 1st STEP\n");
		first_step(stacks); // sorting correctly.
	}
	// printf("nbr_moves after 1st step:%d\n", stacks->nbr_moves);
	check_order_a_v1(stacks);
	if (stacks->sorted == false)
	{
		printf("ENTERING 2nd STEP\n");
		second_step(stacks);
	}
	check_order_a_v1(stacks);
	if (stacks->sorted == false)
	{
		printf("ENTERING 3rd STEP\n");
		third_step(stacks);
	}
	check_order_a_v1(stacks);
	if (stacks->sorted == false)
	{
		if (stacks->head_a && stacks->head_b &&\
		stacks->head_a->next != NULL && stacks->head_b->next != NULL)
		{
			printf("ENTERING 4th STEP\n");
			fourth_step(stacks);
		}
	}	
	check_order_a_v1(stacks);
	if (stacks->sorted == false)
	{
		printf("ENTERING 5th STEP\n");
		fifth_step(stacks);
	}
	printf("STEPS MASTER DONE\n");
	// printf("nbr_moves after 5th step:%d\n", stacks->nbr_moves);
	// stacks = second_step(stacks); // sorting correctly!
	*/
}
