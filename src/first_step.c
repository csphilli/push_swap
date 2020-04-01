/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 14:46:52 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/01 21:35:26 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		first_step(t_stacks *stacks)
{
    // printf("FIRST STEP START\n");
    
	// t_stacks *tmp;
    bool    check;
    t_lists *tail_a;
    int i;
	
    // tmp = stacks;
    tail_a = stacks->head_a;
    i = 0;
    check = true;
    // display_list(stacks->head_a);
	if (stacks->head_a->next != NULL)
	{
        while (check)
        {
            tail_a = stacks->head_a;
            // printf("first step count:%d\n", i);
            while (tail_a->next != NULL)
                tail_a = tail_a->next;
            // printf("head_a->nbr:%d\n", stacks->head_a->nbr);
            // printf("tail_a->nbr:%d\n", tail_a->nbr);
            if (stacks->head_a->nbr > tail_a->nbr)
            {
                
                ra(stacks);
                // Each time i execute this step, i must output "ra" for GNL to pick up.
                // printf("\n");
            }
            else
                check = false;
            i++;
        }
	}
    // printf("FIRST STEP END\n");
    // display_list(stacks->head_a);
	// return (tmp);
}



// void		first_step(t_stacks *stacks)
// {
//     // printf("FIRST STEP START\n");
    
// 	// t_stacks *tmp;
//     bool    check;
// 	t_lists	*head_a;
//     t_lists *tail_a;
//     int i;
	
//     // tmp = stacks;
//     i = 0;
//     check = true;
// 	head_a = stacks->head_a;
// 	tail_a = stacks->head_a;
//     // display_list(stacks->head_a);
// 	if (head_a->next != NULL)
// 	{
//         while (check)
//         {
//             printf("first step count:%d\n", i);
//             while (tail_a->next != NULL)
//                 tail_a = tail_a->next;
//             // printf("tail_a:%d\n", tail_a->nbr);
//             if (head_a->nbr > tail_a->nbr)
//             {
                
//                 ra(stacks);
//                 // Each time i execute this step, i must output "ra" for GNL to pick up.
//                 // printf("\n");
//             }
//             else
//                 check = false;
//             i++;
//         }
// 	}
//     // printf("FIRST STEP END\n");
//     // display_list(stacks->head_a);
// 	// return (tmp);
// }