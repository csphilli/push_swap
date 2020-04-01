/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_master.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 14:41:13 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/01 22:27:58 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	begin_sort(t_stacks *stacks)
{
	// printf("BEGIN SORT\n");
	// printf("nbr_moves START:%d\n", stacks->nbr_moves);
	check_order(stacks);
	if (stacks->sorted == false)
	{
		printf("ENTERING 1st STEP\n");
		first_step(stacks); // sorting correctly.
	}
	// printf("nbr_moves after 1st step:%d\n", stacks->nbr_moves);
	check_order(stacks);
	if (stacks->sorted == false)
	{
		printf("ENTERING 2nd STEP\n");
		second_step(stacks);
	}
	check_order(stacks);
	if (stacks->sorted == false)
	{
		printf("ENTERING 3rd STEP\n");
		third_step(stacks);
	}
	check_order(stacks);
	if (stacks->sorted == false)
	{
		if (stacks->head_a && stacks->head_b &&\
		stacks->head_a->next != NULL && stacks->head_b->next != NULL)
		{
			printf("ENTERING 4th STEP\n");
			fourth_step(stacks);
		}
	}	
	check_order(stacks);
	if (stacks->sorted == false)
	{
		printf("ENTERING 5th STEP\n");
		fifth_step(stacks);
	}
	printf("STEPS MASTER DONE\n");
	// printf("nbr_moves after 5th step:%d\n", stacks->nbr_moves);
	// stacks = second_step(stacks); // sorting correctly!
}
