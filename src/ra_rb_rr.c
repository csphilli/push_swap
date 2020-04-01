/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:33:26 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/01 14:53:55 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void		ra(t_stacks *stacks) // this needs to be part of checker
{
	// t_stacks	*tmp;
	t_lists		*tmp_head;
	t_lists		*head;
	t_lists		*tail;

	// tmp = stacks;
	head = stacks->head_a;
	tail = stacks->head_a;
	tmp_head = head;
	// printf("ROTATE LIST - LIST START\n");
	// display_list(stacks->head_a);
	if (stacks->head_a != NULL || stacks->head_a->next != NULL)
	{
		while (tail->next != NULL)
			tail = tail->next;
		tmp_head = head->next;
		// printf("tail:%d\n", tail->nbr);
		tail->next = head;
		tail = tail->next;
		tail->next = NULL;
		// printf("head:%d\n", head->nbr);
		stacks->head_a = tmp_head;
		stacks->nbr_moves++;
	}
	// printf("ROTATE LIST - LIST END\n");
	// display_list(stacks->head_a);
	// return (tmp);
}

void		rb(t_stacks *stacks) // this needs to be part of checker
{
	// t_stacks	*tmp;
	t_lists		*tmp_head;
	t_lists		*head;
	t_lists		*tail;

	// tmp = stacks;
	head = stacks->head_b;
	tail = stacks->head_b;
	tmp_head = head;
	// printf("ROTATE LIST - LIST START\n");
	// display_list(stacks->head_b);
	if (stacks->head_b != NULL || stacks->head_b->next != NULL)
	{
		while (tail->next != NULL)
			tail = tail->next;
		tmp_head = head->next;
		// printf("tail:%d\n", tail->nbr);
		tail->next = head;
		tail = tail->next;
		tail->next = NULL;
		// printf("head:%d\n", head->nbr);
		stacks->head_b = tmp_head;
		stacks->nbr_moves++;
	}
	// printf("ROTATE LIST - LIST END\n");
	// display_list(stacks->head_b);
	// return (tmp);
}

void		rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
	stacks->nbr_moves--;
}