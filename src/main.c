/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 19:00:19 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/04 12:26:00 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	
	stacks = create_stacks();
	if (ac > 1)
		stacks = run_program(stacks, ac, av);
	else
		ERROR;
	printf("LIST A\n");
	display_list(stacks->head_a);
	// printf("LIST B\n");
	// if (stacks->head_b != NULL)	
	// 	display_list(stacks->head_b);
	printf("STATS: LIST_A_LEN_START:%2d | NBR MOVES:%3d | LEN_B:%d\n", stacks->list_a_len_start,\
		stacks->nbr_moves, stacks->list_len_b);
	// LEAK TESTING
	// check_order_a_v1(stacks);
	// stacks->sorted == true ? printf("List A sorted\n") : printf("List A NOT sorted\n");

	while (1)
	{
	}
	return (0);
}
