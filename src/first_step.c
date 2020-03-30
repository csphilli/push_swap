/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 14:46:52 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/30 14:47:16 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lists		*first_step(t_stacks *stacks, t_lists *list_a)
{
	t_lists *head_a;
	t_lists	*tail_a;
	
	head_a = list_a;
	tail_a = head_a;
	if (head_a->next != NULL)
	{
		while (tail_a->next != NULL)
			tail_a = tail_a->next;
		if (head_a->nbr > tail_a->nbr)
		{
			// display_list(head_a);
			head_a = first_step(stacks, rotate_list(stacks, head_a));
			// Each time i execute this step, i must output "ra" for GNL to pick up.
			// printf("\n");
		}
	}
	return (head_a);
}