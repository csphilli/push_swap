/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 10:12:03 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/13 15:10:11 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	The allowed manipulation functions stipulated in the instructions.
**	The toggle is used to handle the printing of the respective functions.
**	If push_swap sends the instructions, it is sent with a 0 and hence
**	will print the instruction. Checker sends a 1 so it will not print.
**	Also notice that rrr sends a 1 to both rra and rrb since only rrr should
**	be printed.
*/

void	rra(t_stacks *stacks, int toggle)
{
	t_lists *tail;
	t_lists *tail_minus_one;

	tail = stacks->head_a;
	tail_minus_one = tail;
	if (stacks && stacks->head_a->next != NULL)
	{
		while (tail_minus_one->next->next != NULL)
			tail_minus_one = tail_minus_one->next;
		tail = tail_minus_one;
		tail = tail->next;
		tail->next = stacks->head_a;
		tail_minus_one->next = NULL;
		stacks->head_a = tail;
		stacks->moves_a--;
		if (toggle == 0)
			ft_putendl("rra");
	}
}

void	rrb(t_stacks *stacks, int toggle)
{
	t_lists *tail;
	t_lists *tail_minus_one;

	tail = stacks->head_b;
	tail_minus_one = tail;
	if (stacks && stacks->head_b->next != NULL)
	{
		while (tail_minus_one->next->next != NULL)
			tail_minus_one = tail_minus_one->next;
		tail = tail_minus_one;
		tail = tail->next;
		tail->next = stacks->head_b;
		tail_minus_one->next = NULL;
		stacks->head_b = tail;
		stacks->moves_b--;
		if (toggle == 0)
			ft_putendl("rrb");
	}
}

void	rrr(t_stacks *stacks, int toggle)
{
	rra(stacks, 1);
	rrb(stacks, 1);
	if (toggle == 0)
		ft_putendl("rrr");
}
