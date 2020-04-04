/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_for_duplicates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 13:16:20 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/30 13:17:02 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	scan_for_duplicates(t_stacks *stacks)
{
	t_lists *base;
	t_lists *iterate;

	base = stacks->head_a;
	iterate = base;
	if (base->next != NULL)
	{
		while (base->next != NULL)
		{
			iterate = base->next;
			while (iterate != NULL)
			{
				if (iterate->nbr == base->nbr)
					ERROR;
				iterate = iterate->next;
			}
			base = base->next;
		}
	}
}

void	scan_for_min_max_a(t_stacks *stacks)
{
	t_lists *a;

	a = stacks->head_a;
	stacks->a_max = a->nbr;
	stacks->a_min = a->nbr;
	while (a != NULL)
	{
		stacks->a_max = a->nbr > stacks->a_max ? a->nbr : stacks->a_max;
		stacks->a_min = a->nbr < stacks->a_min ? a->nbr : stacks->a_min;
		a = a->next;
	}
}

void	scan_for_min_max_b(t_stacks *stacks)
{
	t_lists *b;

	b = stacks->head_b;
	stacks->b_max = b->nbr;
	stacks->b_min = b->nbr;
	while (b->next != NULL)
	{
		stacks->b_max = b->nbr > stacks->b_max ? b->nbr : stacks->b_max;
		stacks->b_min = b->nbr < stacks->b_min ? b->nbr : stacks->b_min;
		b = b->next;
	}
}

void	print_min_max_lists(t_stacks *stacks)
{
	printf("a_max = %d\n", stacks->a_max);
	printf("a_min = %d\n", stacks->a_min);
	printf("b_max = %d\n", stacks->b_max);
	printf("b_min = %d\n", stacks->b_min);
}