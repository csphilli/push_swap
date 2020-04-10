/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 11:17:54 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/10 23:11:16 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_more_short(t_stacks *stacks)
{
	t_lists *a;

	a = stacks->head_a;
	if (a->nbr != stacks->a_min && a->next->next->nbr == stacks->a_max)
		// ft_putendl("sa");
		// exec_parse(stacks, "sa");
		sa(stacks, 0);
	else if (a->nbr != stacks->a_max && a->next->next->nbr == stacks->a_min)
		// ft_putendl("rra");
		// exec_parse(stacks, "rra");
		rra(stacks, 0);
	else if (a->nbr == stacks->a_max && a->next->next->nbr != stacks->a_min)
		// ft_putendl("ra");
		// exec_parse(stacks, "ra");
		ra(stacks, 0);
	else if (a->nbr == stacks->a_max && a->next->next->nbr == stacks->a_min)
	{
		// ft_putendl("ra");
		// ft_putendl("sa");
		// exec_parse(stacks, "ra");
		// exec_parse(stacks, "sa");
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
		// ft_putendl("sa");
		// ft_putendl("rra");
		// exec_parse(stacks, "sa");
		// exec_parse(stacks, "rra");
		sa(stacks, 0);
		rra(stacks, 0);
	}
	else if (a->nbr == stacks->a_min && a->next->next->nbr != stacks->a_max)
	{
		// ft_putendl("rra");
		// ft_putendl("sa");
		// exec_parse(stacks, "rra");
		// exec_parse(stacks, "sa");
		rra(stacks, 0);
		sa(stacks, 0);
	}
	else
		do_more_short(stacks);
}

void		sort_two_numbers(t_stacks *stacks)
{
	if (stacks->head_a->nbr > stacks->head_a->next->nbr)
		// ft_putendl("sa");
		// exec_parse(stacks, "sa");
		sa(stacks, 0);
}
