/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:33:26 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/09 17:49:16 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ra(t_stacks *stacks, int nbr) // this needs to be part of checker
{
	t_lists		*tmp_head;
	t_lists		*head;
	t_lists		*tail;

	head = stacks->head_a;
	tail = stacks->head_a;
	tmp_head = head;
	if (stacks->head_a != NULL || stacks->head_a->next != NULL)
	{
		while (tail->next != NULL)
			tail = tail->next;
		tmp_head = head->next;
		tail->next = head;
		tail = tail->next;
		tail->next = NULL;
		stacks->head_a = tmp_head;
		stacks->moves_a--;
		if (nbr == 0)
			ft_putendl("ra");
	}
}

void		rb(t_stacks *stacks, int nbr) // this needs to be part of checker
{
	t_lists		*tmp_head;
	t_lists		*head;
	t_lists		*tail;

	head = stacks->head_b;
	tail = stacks->head_b;
	tmp_head = head;
	if (stacks->head_b != NULL || stacks->head_b->next != NULL)
	{
		while (tail->next != NULL)
			tail = tail->next;
		tmp_head = head->next;
		tail->next = head;
		tail = tail->next;
		tail->next = NULL;
		stacks->head_b = tmp_head;
		stacks->moves_b--;
		if (nbr == 0)
			ft_putendl("rb");
		
	}
}

void		rr(t_stacks *stacks, int nbr)
{
	ra(stacks, nbr);
	rb(stacks, nbr);
	if (nbr == 1)
		ft_putendl("rr");
}