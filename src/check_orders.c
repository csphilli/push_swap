/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order_a_v1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 14:57:12 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/01 22:36:14 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_order_a_v1(t_stacks *stacks)
{
	// printf("CHECK A ORDER START\n");
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
				// printf("CHECK A ORDER FINISHED - SORTED\n");
				stacks->sorted = true;
			}
		}
	}
	// printf("CHECK A ORDER FINISHED - NOT SORTED\n");
}

void	check_order_a(t_stacks *stacks)
{
	// printf("CHECK A ORDER START\n");
	// display_list(stacks->head_a);
	// printf("\nLIST B\n");
	// if (stacks->head_b != NULL)
	// 	display_list(stacks->head_b);
	t_lists *head;
	t_lists *second;

	head = stacks->head_a;
	second = stacks->head_a;
	stacks->a_sorted = false;
	if (head)
	{
		// if (head->next == NULL)
		// 	stacks->a_sorted = true;
		second = head->next;
		while (second != NULL)
		{
			// printf("head->nbr:%d | second->nbr:%d | second->next:%p\n", head->nbr, second->nbr, second->next);
			if (head->nbr > second->nbr)
				break ;
			else if (second->next == NULL && head->nbr < second->nbr)
			{
				// printf("A IN ORDER (ASCENDING\n");
				stacks->a_sorted = true;
				// break ;
			}
			head = head->next;
			second = second->next;
		}
	}
	// stacks->a_sorted == true ? printf("A SORTED (ASCENDING)\n") : printf("A NOT SORTED\n");
	// printf("LIST B\n");
	// display_list(stacks->head_b);
}

void	check_order_b(t_stacks *stacks)
{
	// printf("CHECK B ORDER START\n");
	// display_list(stacks->head_a);
	// printf("\nLIST B\n");
	// if (stacks->head_b != NULL)
	// 	display_list(stacks->head_b);
	t_lists *head;
	t_lists *second;

	head = stacks->head_b;
	second = stacks->head_b;
	stacks->b_sorted = false;
	// printf("head->next:%p\n", head->next);
	if (head != NULL)
	{
		// if (head->next == NULL)
		// 	stacks->b_sorted = true;
		second = head->next;
		while (second != NULL)
		{				
			// printf("head_b->nbr:%d | second_b->nbr:%d | second_b->next:%p\n", head->nbr, second->nbr, second->next);
			if (head->nbr < second->nbr)
				break ;
			else if (second->next == NULL && head->nbr > second->nbr)
			{
				// printf("B IN ORDER (DESCENDING\n");
				stacks->b_sorted = true;
				// break ;
			}
			head = head->next;
			second = second->next;	
		}
	}
	// stacks->b_sorted == true ? printf("B SORTED (DESCENDING)\n") : printf("B NOT SORTED\n");
	// printf("LIST A\n");
	// display_list(stacks->head_a);
}

void	check_full_sort(t_stacks *stacks)
{
	// printf("CHECK COMPLETE SORT\n");
	// display_list(stacks->head_a);
	// printf("\nLIST B\n");
	// if (stacks->head_b != NULL)
	// 	display_list(stacks->head_b);
	if (stacks->head_b != NULL)
		stacks->full_sort = false;
	else if (stacks->head_a && stacks->head_b == NULL)
	{
		check_order_a(stacks);
		if (stacks->a_sorted == true)
			stacks->full_sort = true;
	}
	// stacks->a_sorted == true ? printf("A SORTED (ASCENDING)\n") : printf("A NOT SORTED\n");
}