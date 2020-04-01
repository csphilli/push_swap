/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 14:46:52 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/01 14:25:26 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		first_step(t_stacks *stacks)
{
    // printf("FIRST STEP START\n");
    
	// t_stacks *tmp;
    bool    check;
	t_lists	*head_a;
    t_lists *tail_a;
	
    // tmp = stacks;
    check = true;
	head_a = stacks->head_a;
	tail_a = stacks->head_a;
    // display_list(stacks->head_a);
	if (head_a->next != NULL)
	{
        while (check)
        {
            while (tail_a->next != NULL)
                tail_a = tail_a->next;
            // printf("tail_a:%d\n", tail_a->nbr);
            if (head_a->nbr > tail_a->nbr)
            {
                
                ra(stacks);
                // Each time i execute this step, i must output "ra" for GNL to pick up.
                // printf("\n");
            }
            else
                check = false;
        }
	}
    // printf("FIRST STEP END\n");
    // display_list(stacks->head_a);
	// return (tmp);
}
