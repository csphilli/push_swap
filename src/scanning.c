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

/*
**	Standard duplicate checker function.
*/

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

/*
**	Finds the min and max value from stack a. Again, I could have used a single
**	function for both lists but I was thinking just passing the struct
**	that contained both stack addresses instead. Don't feel like refactoring
**	the code at this point.
*/

void	min_max_a(t_stacks *stacks)
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
