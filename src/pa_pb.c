/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:50:28 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/09 17:52:52 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stacks *stacks)
{
	// if (stacks->head_b != NULL)
	// {
		unshift_a(stacks, stacks->head_b->nbr);
		pop_b(stacks);
		stacks->ll_b_cur--;
		stacks->ll_a_cur++;
		ft_putendl("pa");
	// }
}

void	pb(t_stacks *stacks)
{
	// if (stacks->head_a != NULL)
	// {
		unshift_b(stacks, stacks->head_a->nbr);
		pop_a(stacks);
		stacks->ll_b_cur++;
		stacks->ll_a_cur--;
		ft_putendl("pb");
	// }
}


