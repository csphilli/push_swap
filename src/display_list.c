/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 10:34:16 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/08 18:55:46 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		display_list(t_lists *list)
{
	int i;

	i = 1;
	t_lists *tmp;
	tmp = list;
	if (tmp)
	{
		while (tmp != NULL)
		{
			printf("address:%p | list[%2d]:%3d | next:%p\n", tmp, i, tmp->nbr, tmp->next); // change to ft_printf
			// printf("seg fault here?\n");
			tmp = tmp->next;
			// printf("or here?\n");
			i++;
		}
	}
}

// void		display_moves(t_stacks *stacks)
// {
// 	printf("MOVES TO TOP: A\nmin: %d | max: %d\n", stacks->moves_a_min, stacks->moves_a_max);
// 	printf("MOVES TO TOP: B\nmin: %d | max: %d\n", stacks->moves_b_min, stacks->moves_b_max);
// }
