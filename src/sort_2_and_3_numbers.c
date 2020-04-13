/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_and_3_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 11:17:54 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/13 15:35:05 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Hard coding the sorting of 2 and 3 numbers since the larger algo fails
**	the number of moves requirement set by moulinette.
*/

static void	sort_three_numbers_cont(t_stacks *stacks)
{
	t_lists *a;

	a = stacks->head_a;
	if (a->nbr != stacks->a_min && a->next->next->nbr == stacks->a_max)
		sa(stacks, 0);
	else if (a->nbr != stacks->a_max && a->next->next->nbr == stacks->a_min)
		rra(stacks, 0);
	else if (a->nbr == stacks->a_max && a->next->next->nbr != stacks->a_min)
		ra(stacks, 0);
	else if (a->nbr == stacks->a_max && a->next->next->nbr == stacks->a_min)
	{
		ra(stacks, 0);
		sa(stacks, 0);
	}
}

void		sort_three_numbers(t_stacks *stacks)
{
	t_lists *a;

	a = stacks->head_a;
	min_max_a(stacks);
	check_order_a(stacks);
	if (a->nbr == stacks->a_min && a->next->next->nbr == stacks->a_max)
	{
		sa(stacks, 0);
		rra(stacks, 0);
	}
	else if (a->nbr == stacks->a_min && a->next->next->nbr != stacks->a_max)
	{
		rra(stacks, 0);
		sa(stacks, 0);
	}
	else
		sort_three_numbers_cont(stacks);
}

void		sort_two_numbers(t_stacks *stacks)
{
	if (stacks->head_a->nbr > stacks->head_a->next->nbr)
		sa(stacks, 0);
}
