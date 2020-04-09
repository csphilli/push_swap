/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pops.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 14:28:45 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/09 14:29:17 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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