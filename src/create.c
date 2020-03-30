/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 13:12:23 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/30 13:15:17 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stacks	*create_stacks(void)
{
	t_stacks	*new;

	new = (t_stacks*)malloc(sizeof(t_stacks));
	new = initialize_stacks(new);
	return (new);
}

t_stacks	*initialize_stacks(t_stacks *stack)
{
	stack->head_a = NULL;
	stack->head_b = NULL;
	stack->midpoint = 0;
	stack->list_len_start = 0;
	stack->nbr_moves = 0;
	return (stack);
}

t_lists		*create_new_node(int nbr)
{
	t_lists		*new;

	new = (t_lists*)malloc(sizeof(t_lists));
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}