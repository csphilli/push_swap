/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 11:17:54 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/09 16:14:48 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_more_short(t_stacks *stacks)
{
	t_lists *a;

	a = stacks->head_a;
	if (a->nbr != stacks->a_min && a->next->next->nbr == stacks->a_max)
		exec_parse(stacks, "sa");
		// sa(stacks);
	else if (a->nbr != stacks->a_max && a->next->next->nbr == stacks->a_min)
		exec_parse(stacks, "rra");
		// rra(stacks, 0);
	else if (a->nbr == stacks->a_max && a->next->next->nbr != stacks->a_min)
		exec_parse(stacks, "ra");
		// ra(stacks, 0);
	else if (a->nbr == stacks->a_max && a->next->next->nbr == stacks->a_min)
	{
		exec_parse(stacks, "ra");
		exec_parse(stacks, "sa");
		// ra(stacks, 0);
		// sa(stacks);
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
		exec_parse(stacks, "sa");
		exec_parse(stacks, "rra");
		// sa(stacks);
		// rra(stacks, 0);
	}
	else if (a->nbr == stacks->a_min && a->next->next->nbr != stacks->a_max)
	{
		exec_parse(stacks, "rra");
		exec_parse(stacks, "sa");
		// rra(stacks, 0);
		// sa(stacks);
	}
	else
		do_more_short(stacks);
}

void		sort_two_numbers(t_stacks *stacks)
{
	if (stacks->head_a->nbr > stacks->head_a->next->nbr)
		exec_parse(stacks, "sa");
		// sa(stacks);
}
