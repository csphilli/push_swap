/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:50:28 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/30 18:56:41 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stacks	*pb(t_stacks *stacks)
{
	// printf("PUSH B - LISTS START\n");
	
	t_stacks 	*tmp;
	t_lists		*head_a;
	t_lists		*head_b;

	tmp = stacks;
	head_a = tmp->head_a;
	head_b = tmp->head_b;
	// printf("HEAD_A\n");
	// display_list(head_a);
	// printf("HEAD_B\n");
	// display_list(head_b);
	tmp->head_b = list_push(head_a->nbr, head_b);
	tmp->head_a = list_pop(head_a);
	// printf("LISTS AFTER PB FINISHES\n");
	// display_list(tmp->head_a);
	// display_list(tmp->head_b);
	return (tmp);
	// pop removes the top element of the list.
	// push adds an element to the top of the stack.
}
