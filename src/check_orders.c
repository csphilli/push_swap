/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_orders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:26:18 by cphillip          #+#    #+#             */
/*   Updated: 2020/06/18 15:14:38 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Functions handling the checking of whether a list is sorted or not.
**	Here again, I could have made a single function to handle the checking.
**	Too far along to bother refactoring at this point. Need to keep progressing
**	in order to not fall behind.
*/

void	check_order_a(t_stacks *stacks)
{
	t_lists *head;
	t_lists *second;

	head = stacks->head_a;
	second = stacks->head_a;
	stacks->a_sorted = false;
	if (head && head != NULL)
	{
		second = head->next;
		while (second != NULL)
		{
			if (head->nbr > second->nbr)
				break ;
			else if (second->next == NULL && head->nbr < second->nbr)
				stacks->a_sorted = true;
			head = head->next;
			second = second->next;
		}
	}
}

void	check_order_b(t_stacks *stacks)
{
	t_lists *head;
	t_lists *second;

	head = stacks->head_b;
	second = stacks->head_b;
	stacks->b_sorted = false;
	if (head && head != NULL)
	{
		second = head->next;
		while (second != NULL)
		{
			if (head->nbr < second->nbr)
				break ;
			else if (second->next == NULL && head->nbr > second->nbr)
				stacks->b_sorted = true;
			head = head->next;
			second = second->next;
		}
	}
}

void	check_full_sort(t_stacks *stacks)
{
	if (stacks->head_a && stacks->head_a->next != NULL)
	{
		if (stacks->head_b != NULL)
			stacks->full_sort = false;
		else if (stacks->head_a && stacks->head_b == NULL)
		{
			check_order_a(stacks);
			if (stacks->a_sorted == true)
				stacks->full_sort = true;
		}
	}
}
