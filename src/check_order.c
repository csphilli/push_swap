/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 14:57:12 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/01 22:36:14 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_order(t_stacks *stacks)
{
	printf("CHECK ORDER START\n");
	// display_list(stacks->head_a);
	// printf("\nLIST B\n");
	// if (stacks->head_b != NULL)
	// 	display_list(stacks->head_b);
	t_lists *head;
	t_lists *second;

	head = stacks->head_a;
	second = stacks->head_a;
	if (head && head->next == NULL && stacks->head_b == NULL)
		stacks->sorted = true;
	else if (head && head->next != NULL && stacks->head_b == NULL)
	{
		second = second->next;
		while (head && second && head->nbr < second->nbr && stacks->sorted == false)
		{
			head = head->next;
			second = second->next;
			if (second->next == NULL && head->nbr < second->nbr)
			{
				printf("CHECK ORDER FINISHED - SORTED\n");
				stacks->sorted = true;
			}
		}
	}
	printf("CHECK ORDER FINISHED - NOT SORTED\n");
}