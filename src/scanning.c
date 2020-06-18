/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:37:51 by cphillip          #+#    #+#             */
/*   Updated: 2020/06/18 11:10:56 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Standard duplicate checker function.
*/

static void	dup_error(t_stacks *stacks, int nbr)
{
	if (stacks->advanced == 1)
		ft_printf("Error: Duplicate value "YELLOW"%d"RESET" found.", nbr);
	else
		ft_printf("Error");
	ft_printf("\n");
	exit(-1);
}

void		scan_for_duplicates(t_stacks *stacks)
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
					dup_error(stacks, iterate->nbr);
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

void		min_max_a(t_stacks *stacks)
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
