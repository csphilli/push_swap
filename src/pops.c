/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pops.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 14:28:45 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/13 15:02:13 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Functions to handle the removal of node from a specific list. In retrospect
**	I could have added a single function and just passed the respective list.
**	However, my thinking from the beginning was that I'd simply pass the entire
**	stack struct which included head_a and head_b. I don't want to refactor the
**	entire project at this point.
*/

void		pop_a(t_stacks *stacks)
{
	t_lists *tmp;
	t_lists *head;

	head = stacks->head_a;
	tmp = head;
	head = tmp->next;
	tmp->nbr = '\0';
	tmp->next = NULL;
	stacks->head_a = head;
	free(tmp);
}

void		pop_b(t_stacks *stacks)
{
	t_lists *head;
	t_lists *tmp;

	head = stacks->head_b;
	tmp = head;
	if (tmp->next != NULL)
	{
		head = tmp->next;
		tmp->next = NULL;
		stacks->head_b = head;
	}
	else
		stacks->head_b = NULL;
	free(tmp);
}