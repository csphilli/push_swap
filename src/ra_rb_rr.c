/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:33:26 by csphilli          #+#    #+#             */
/*   Updated: 2020/06/18 13:52:42 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	The allowed manipulation functions stipulated in the instructions.
**	The toggle is used to handle the printing of the respective functions.
**	If push_swap sends the instructions, it is sent with a 0 and hence
**	will print the instruction. Checker sends a 1 so it will not print.
**	Also notice that rr sends a 1 to both ra and rb since only rr should
**	be printed.
*/

void		ra(t_stacks *stacks, int toggle)
{
	t_lists		*tmp_head;
	t_lists		*head;
	t_lists		*tail;

	head = stacks->head_a;
	tail = stacks->head_a;
	tmp_head = head;
	if (head && head->next != NULL)
	{
		while (tail->next != NULL)
			tail = tail->next;
		tmp_head = head->next;
		tail->next = head;
		tail = tail->next;
		tail->next = NULL;
		stacks->head_a = tmp_head;
		stacks->moves_a--;
		if (toggle == 0)
			ft_putendl("ra");
	}
}

void		rb(t_stacks *stacks, int toggle)
{
	t_lists		*tmp_head;
	t_lists		*head;
	t_lists		*tail;

	head = stacks->head_b;
	tail = stacks->head_b;
	tmp_head = head;
	if (head && head->next != NULL)
	{
		while (tail->next != NULL)
			tail = tail->next;
		tmp_head = head->next;
		tail->next = head;
		tail = tail->next;
		tail->next = NULL;
		stacks->head_b = tmp_head;
		stacks->moves_b--;
		if (toggle == 0)
			ft_putendl("rb");
	}
}

void		rr(t_stacks *stacks, int toggle)
{
	ra(stacks, 1);
	rb(stacks, 1);
	if (toggle == 0)
		ft_putendl("rr");
}
