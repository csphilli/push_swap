/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 14:57:12 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/01 15:15:32 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_order(t_stacks *stacks)
{
	bool	sort_check;
	t_lists *tmp;

	sort_check = true;
	tmp = stacks->head_a;
	if (tmp && stacks->head_b == NULL)
	{
		while (tmp->next != NULL)
		{
			if (tmp->nbr > tmp->next->nbr)
				sort_check = false;
			tmp = tmp->next;
		}
	}
	stacks->sorted = sort_check;
	// return (stacks);
}