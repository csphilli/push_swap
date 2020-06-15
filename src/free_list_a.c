/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 12:00:02 by csphilli          #+#    #+#             */
/*   Updated: 2020/06/15 13:35:31 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Used to delete the linked list before the program quits in order to free
**	up the memory. However, once the program terminates, the memory is freed
**	anyways. This is also run once stack B has been sorted to A. It's a
**	failsafe to ensure stack B is properly empty and NULL.
*/

void	free_list_a(t_stacks *stacks)
{
	t_lists *tmp;
	t_lists *curr;

	tmp = stacks->head_a;
	while (tmp)
	{
		curr = tmp;
		tmp = tmp->next;
		curr->nbr = '\0';
		curr->next = NULL;
		free(curr);
	}
}
