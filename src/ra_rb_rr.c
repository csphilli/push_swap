/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:33:26 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/08 19:23:46 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void		ra(t_stacks *stacks, int nbr) // this needs to be part of checker
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
		stacks->moves_a--;
		if (nbr == 0)
			printf("ra - nbr_moves:%d\n", stacks->nbr_moves);
	}
	// printf("ROTATE LIST - LIST END\n");
	// display_list(stacks->head_a);
	// return (tmp);
}

void		rb(t_stacks *stacks, int nbr) // this needs to be part of checker
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
		stacks->moves_b--;
		if (nbr == 0)
			printf("rb - nbr_moves:%d\n", stacks->nbr_moves);
		
	}
	// printf("ROTATE LIST - LIST END\n");
	// display_list(stacks->head_b);
	// return (tmp);
}

void		rr(t_stacks *stacks, int nbr)
{
	// add a toggle here to tell ra and rb whether or not the instruction came from rr. it'll be used
	// to control whether ra or rb print an instruction. clear the toggle once the commands run.
	ra(stacks, nbr);
	rb(stacks, nbr);
	stacks->nbr_moves--;

	printf("rr - nbr_moves:%d\n", stacks->nbr_moves);
}