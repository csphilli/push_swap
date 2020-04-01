/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:50:28 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/01 21:18:08 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stacks *stacks)
{
	unshift_a(stacks, stacks->head_b->nbr);
	pop_b(stacks);
	stacks->list_len_b--;
	stacks->nbr_moves++;
	printf("pa - nbr_moves:%d\n", stacks->nbr_moves);
}

void	pb(t_stacks *stacks)
{
	unshift_b(stacks, stacks->head_a->nbr);
	pop_a(stacks);
	stacks->list_len_b++;
	stacks->nbr_moves++;
	printf("pb - nbr_moves:%d\n", stacks->nbr_moves);
}


