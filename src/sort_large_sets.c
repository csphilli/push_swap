/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_sets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 19:11:35 by csphilli          #+#    #+#             */
/*   Updated: 2020/06/23 11:10:05 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Tidy up is used at the end of the large sorting algo. It evaluates
**	whether the min number is before or after the midpoint and rotates
**	the list using the minimal amount of moves. ra if the nbr is equal to
**	or before the midpoint and rra if not.
*/

static void	tidy_up(t_stacks *stacks)
{
	min_max_a(stacks);
	if (stacks->pos_a_min <= stacks->ll_a_cur / 2)
		while (stacks->head_a->nbr != stacks->a_min)
			ra(stacks, 0);
	else
		while (stacks->head_a->nbr != stacks->a_min)
			rra(stacks, 0);
}

/*
**	The main sorting algorithm for large numbers. First it evaluates
**	what the next move will be. Get_next is a file on its own. Check
**	that out for more information. moves_a and moves_b are found in the
**	get_directions file. The if statement here needs some explanation
**	though. The directions to the top of the list all use a midpoint
**	calculation. If the nbr in question is <= the midpoint, it'll
**	use ra or rb else, rra or rrb.
*/

void		the_big_sort(t_stacks *stacks)
{
	t_lists *next_move;

	while (stacks->head_b)
	{
		next_move = get_next(stacks->head_a, stacks->head_b);
		stacks->moves_a = to_top(stacks->head_a,
			next_large(stacks->head_a, next_move->nbr));
		stacks->moves_b = to_top(stacks->head_b, next_move->nbr);
		stacks->dir_a = get_dir(stacks->head_a,
		next_large(stacks->head_a, next_move->nbr));
		stacks->dir_b = get_dir(stacks->head_b, next_move->nbr);
		sort_b_to_a(stacks);
	}
	tidy_up(stacks);
}

/*
**	Dir Mod is used in conjunction with get_next found in the
**	get_next file. It is used to return the least number of moves
**	from either list a or b if the direction of those moves
**	to the top of their stacks is the same, or zero which would
**	mean that the direction to the top is not the same.
*/

int			dir_mod(t_lists *list_a, int next_nbr, t_lists *list_b, int nbr)
{
	int	dir_a;
	int	dir_b;
	int	moves_a;
	int	moves_b;

	dir_a = get_dir(list_a, next_nbr);
	dir_b = get_dir(list_b, nbr);
	moves_a = to_top(list_a, next_nbr);
	moves_b = to_top(list_b, nbr);
	if (dir_a == dir_b && moves_a > 0 && moves_b > 0)
	{
		if (moves_a > moves_b)
			return (moves_b);
		else
			return (moves_a);
	}
	else
		return (0);
}
