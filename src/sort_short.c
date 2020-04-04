/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 11:17:54 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/04 14:20:28 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_numbers(t_stacks *stacks)
{
	t_lists *a;

	a = stacks->head_a;
	scan_for_min_max_a(stacks);
	check_order_a(stacks);
		if (a->nbr == stacks->a_min && a->next->next->nbr == stacks->a_max)
		{
			sa(stacks);
			rra(stacks);
		}
		else if (a->nbr == stacks->a_min && a->next->next->nbr != stacks->a_max)
		{
			rra(stacks);
			sa(stacks);
		}
		else if (a->nbr != stacks->a_min && a->next->next->nbr == stacks->a_max)
			sa(stacks);
		else if (a->nbr != stacks->a_max && a->next->next->nbr == stacks->a_min)
			rra(stacks);
		else if (a->nbr == stacks->a_max && a->next->next->nbr != stacks->a_min)
			ra(stacks);
		else if (a->nbr == stacks->a_max && a->next->next->nbr == stacks->a_min)
		{
			ra(stacks);
			sa(stacks);
		}
}

void	sort_two_numbers(t_stacks *stacks)
{
	if (stacks->head_a->nbr > stacks->head_a->next->nbr)
		sa(stacks);
}