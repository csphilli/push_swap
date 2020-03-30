/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:53:05 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/30 18:54:35 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stacks	*run_program(t_stacks *stacks, int ac, char **av)
{
	int			nbr;
	int			i;

	i = 1;
	while (ac-- > 1)
	{
		nbr = ft_atoi(av[i]);
		insert_node(stacks, nbr);
		i++;
	}
	check_for_duplicates(stacks);
	begin_sort(stacks);
	// printf("PRINTING STACKS IN RUN PROGRAM\n");
	// printf("LIST A\n");
	// display_list(stacks->head_a);
	// printf("LIST B\n");
	// display_list(stacks->head_b);
	return (stacks);
}