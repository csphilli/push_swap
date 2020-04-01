/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 09:45:01 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/01 14:07:41 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// this might take some manipulation. for example if list_len A is even, PB
//  directly to exact midpoint. If odd, go 1 beyond the midpoint.

void    third_step(t_stacks *stacks)
{
    int     midpoint;

    midpoint = stacks->list_a_len_start / 2 + 1;
    // printf("midpoint:%d\n", midpoint);
    
    while (stacks->list_len_b < midpoint)
    {
        // printf("list_len_b:%d\n", stacks->list_len_b);
        if (stacks->head_a->nbr > stacks->head_a->next->nbr)
            sa(stacks);
        pb(stacks);
    }
}