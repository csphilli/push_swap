/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 13:12:23 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/09 15:08:49 by csphilli         ###   ########.fr       */
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

t_stacks	*initialize_stacks(t_stacks *stacks)
{
	stacks->head_a = NULL;
	stacks->head_b = NULL;
	stacks->full_sort = false;
	stacks->a_sorted = false; // might not need
	stacks->b_sorted = false; // might not need
	stacks->ll_a_start = 0;
	stacks->ll_a_cur = 0;
	stacks->nbr_moves = 0;
	stacks->ll_b_cur = 0;
	stacks->dir_a = 0;
	stacks->dir_b = 0;
	stacks->moves_a = 0;
	stacks->moves_b = 0;
	return (stacks);
}

void	init_min_max(t_stacks *stacks)
{
	stacks->a_max = '\0';
	stacks->a_min = '\0';
}

t_lists		*create_new_node(int nbr)
{
	t_lists		*new;

	new = (t_lists*)malloc(sizeof(t_lists));
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}