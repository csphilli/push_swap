/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 19:00:19 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/09 14:17:57 by csphilli         ###   ########.fr       */
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
	if (stacks->head_b != NULL)
	{
		printf("LIST B\n");
		display_list(stacks->head_b);
	}
	printf("STATS: ll_a_start:%2d | ll_a_cur:%d | NBR MOVES:%3d | ll_b_cur:%d\n", stacks->ll_a_start,\
		stacks->ll_a_cur, stacks->nbr_moves, stacks->ll_b_cur);

	// while (1)
	// {
	// }
	return (0);
}
