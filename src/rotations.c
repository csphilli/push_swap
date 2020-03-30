/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:33:26 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/30 18:39:35 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**  rotate_list does either RA or RB. Stacks is passed in order to keep track of the
**  number of moves. The list you want to rotate is passed in as the 2nd arg. Which
**  argument Checker picks up is outline in the "step" functions. This eliminates the
**  need to code a separate function for RA or RB since they're the same.
*/

t_lists		*rotate_list(t_stacks *stacks, t_lists *list) // this needs to be part of checker
{
	t_lists *tmp;
	t_lists *head;
	t_lists *tail;

	tmp = list;
	head = tmp;
	tail = tmp;
	// printf("ROTATE LIST - LIST START\n");
	// display_list(head);
	if (tmp != NULL || tmp->next != NULL)
	{
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = tmp;
		head = head->next;
		tmp->next = NULL;
		stacks->nbr_moves++;
	}
	return (head);
}