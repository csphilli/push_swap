/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 13:12:23 by csphilli          #+#    #+#             */
/*   Updated: 2020/06/17 10:33:01 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Creating a new stacks struct.
*/

t_stacks	*create_stacks(void)
{
	t_stacks	*new;

	new = (t_stacks*)malloc(sizeof(t_stacks));
	new = initialize_stacks(new);
	return (new);
}

/*
**	Creating a new node for the linked list.
*/

t_lists		*create_new_node(int nbr)
{
	t_lists		*new;

	new = (t_lists*)malloc(sizeof(t_lists));
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}

/*
**	Initializing the new struct after creation.
*/

t_stacks	*initialize_stacks(t_stacks *stacks)
{
	stacks->head_a = NULL;
	stacks->head_b = NULL;
	stacks->full_sort = false;
	stacks->a_sorted = false;
	stacks->b_sorted = false;
	stacks->ll_a_start = 0;
	stacks->ll_a_cur = 0;
	stacks->ll_b_cur = 0;
	stacks->dir_a = 0;
	stacks->dir_b = 0;
	stacks->moves_a = 0;
	stacks->moves_b = 0;
	stacks->help = 0;
	stacks->color = 0;
	stacks->display = 0;
	return (stacks);
}

/*
**	finding the min and max happens often during the sorting
**	algo so it made sense to re-initialize each time to make sure
**	a non-desirable number isn't being returned.
*/

void		init_min_max(t_stacks *stacks)
{
	stacks->a_max = '\0';
	stacks->a_min = '\0';
}
