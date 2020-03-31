/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 19:00:19 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/30 19:00:36 by csphilli         ###   ########.fr       */
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
	printf("LIST B\n");	
	display_list(stacks->head_b);
	printf("STATS: LIST_LEN_START:%2d | NBR MOVES:%3d\n", stacks->list_len_start,\
		stacks->nbr_moves);
	// LEAK TESTING
	while (1)
	{

	}
	return (0);
}
