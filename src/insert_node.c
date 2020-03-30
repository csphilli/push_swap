/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:51:47 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/30 18:52:15 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		insert_node(t_stacks *stacks, int nbr)
{
	t_lists *tmp;
	t_lists *node;

	node = create_new_node(nbr);
	tmp = stacks->head_a;
	if (stacks && node)
	{
		if (!stacks->head_a)
			stacks->head_a = node;
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = node;
		}
		stacks->list_len_start++;
	}
}