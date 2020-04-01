/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourth_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 10:08:03 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/01 21:05:10 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fourth_step(t_stacks *stacks)
{
	// printf("START FOURTH STEP\n");
	bool	check;
	t_lists *tail_a_prev;
	t_lists *tail_b_prev;
	
	check = true;
	while (check)
	{
		tail_a_prev = stacks->head_a;
		tail_b_prev = stacks->head_b;		
		while (tail_a_prev->next->next != NULL)
			tail_a_prev = tail_a_prev->next;
		while (tail_b_prev->next->next != NULL)
			tail_b_prev = tail_b_prev->next;
		// printf("tail_a_prev->nbr:%d | tail_a->next->nbr:%d\n", tail_a_prev->nbr, tail_a_prev->next->nbr);
		// printf("tail_b_prev->nbr:%d | tail_b->next->nbr:%d\n", tail_b_prev->nbr, tail_b_prev->next->nbr);
		if (stacks->head_a->nbr > tail_a_prev->next->nbr &&\
			stacks->head_b->nbr < tail_b_prev->next->nbr)
			rr(stacks);
		else if (tail_a_prev->next->nbr < tail_a_prev->nbr &&\
				tail_b_prev->next->nbr > tail_b_prev->nbr)
			rrr(stacks);
		else
			check = false;
	}
	// printf("END FOURTH STEP\n");
}