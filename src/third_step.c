/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 09:45:01 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/04 10:46:37 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// this might take some manipulation. for example if list_len A is even, PB
//  directly to exact midpoint. If odd, go 1 beyond the midpoint.

void    third_step(t_stacks *stacks)
{
    // printf("START THIRD STEP\n");
    int     midpoint;

    midpoint = stacks->list_a_len_start / 2;
    // printf("list_a_len_start:%d\n", stacks->list_a_len_start);
    if (stacks->list_a_len_start > 3)
    {
        while (stacks->list_len_b < midpoint)
        {
            // printf("list_len_b:%d\n", stacks->list_len_b);
            if (stacks->head_a->nbr > stacks->head_a->next->nbr)
                sa(stacks);
            pb(stacks);
        }
    }
    else if (stacks->list_a_len_start < 4)
    {
        if (stacks->head_a->nbr > stacks->head_a->next->nbr)
            ra(stacks);
        pa(stacks);
    }
    printf("END THIRD STEP\n");
}