/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:55:38 by csphilli          #+#    #+#             */
/*   Updated: 2020/06/26 17:45:41 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	The bool 'check' passes 2 arguments to get_dir: the list, and the next
**	largest value from stack a compared to the current value of stack b.
**	Get Dir simply evaluates what direction is optimal (shortest) to
**	move the value to the top of the stack. If the direction of move for
**	stack a and b are the same, check will be true, otherwise false.
**
**	Moves computes the total moves to place the current values being
**	examined to the top of their respective stacks. Dir mod is used
**	to evaluate and then subtract the number of moves used when double
**	moves can be utilized since that is the optimal movement.
**
**	The evaluation of whether a new number combination is found to be
**	most effecient occurs in the if statement.
*/

t_lists	*get_next(t_lists *a, t_lists *b)
{
	int		least_moves;
	int		moves;
	t_lists *cur;
	t_lists	*next_move;
	bool	check;

	cur = b;
	next_move = cur;
	least_moves = 999999;
	while (cur)
	{
		moves = 0;
		check = get_dir(a, next_large(a, cur->nbr)) ==
		get_dir(b, cur->nbr) ? true : false;
		moves = to_top(b, cur->nbr) + to_top(a, next_large(a, cur->nbr)) +
		(dir_mod(a, next_large(a, cur->nbr), b, cur->nbr) * -1);
		if ((moves < least_moves) || (moves <= least_moves && check == true))
		{
			next_move = cur;
			least_moves = moves;
		}
		cur = cur->next;
	}
	return (next_move);
}
