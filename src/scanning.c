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

void	min_max_a(t_stacks *stacks)
{
	if (stacks->head_a)
	{
		t_lists *a;
		int		index;

		index = 0;
		a = stacks->head_a;
		stacks->a_max = a->nbr;
		stacks->a_min = a->nbr;
		while (a != NULL)
		{
			if (a->nbr >= stacks->a_max)
			{
				stacks->a_max = a->nbr;
				stacks->pos_a_max = index;
			}
			if (a->nbr <= stacks->a_min)
			{
				stacks->a_min = a->nbr;
				stacks->pos_a_min = index;
			}
			index++;
			a = a->next;
		}
	}
}

// void	min_max_b(t_stacks *stacks)
// {
// 	if (stacks->head_b)
// 	{
// 		t_lists *b;
// 		int		index;

// 		index = 0;
// 		b = stacks->head_b;
// 		stacks->b_max = b->nbr;
// 		stacks->b_min = b->nbr;
// 		while (b != NULL)
// 		{
// 			if (b->nbr >= stacks->b_max)
// 			{
// 				stacks->b_max = b->nbr;
// 				stacks->pos_b_max = index;
// 			}
// 			if (b->nbr <= stacks->b_min)
// 			{
// 				stacks->b_min = b->nbr;
// 				stacks->pos_b_min = index;
// 			}
// 			index++;
// 			b = b->next;
// 		}
// 	}
// }

// void	scan_for_min_max(t_stacks *stacks)
// {
// 	init_min_max(stacks);
// 	min_max_a(stacks);
// 	min_max_b(stacks);
// }

// void	print_min_max_lists(t_stacks *stacks)
// {
// 	printf("a_max = %d\n", stacks->a_max);
// 	printf("a_min = %d\n", stacks->a_min);
// 	printf("b_max = %d\n", stacks->b_max);
// 	printf("b_min = %d\n", stacks->b_min);
// }