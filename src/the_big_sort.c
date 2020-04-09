/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_big_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 19:11:35 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/09 14:50:30 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

static int	what_number(t_lists *list, int moves)
{
	while (list && moves--)
		list = list->next;
	return (list->nbr);
}

void	the_big_sort(t_stacks *stacks)
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
		if (stacks->head_b && what_number(stacks->head_b, 
		ll(stacks->head_b) / 2) == next_move->nbr && ll(stacks->head_b) 
		% 2 == 1)
			stacks->dir_b = stacks->dir_a;
		else
			stacks->dir_b = get_dir(stacks->head_b, next_move->nbr);
		sort_b_to_a(stacks);		
	}
	tidy_up(stacks);
}

int		dir_mod(t_lists *list_a, int next_nbr, t_lists *list_b, int nbr)
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
				return(moves_a);
		}
	else
		return (0);
}
