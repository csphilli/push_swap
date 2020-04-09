/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:53:05 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/09 14:37:51 by csphilli         ###   ########.fr       */
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
		push_a(stacks, nbr);
		i++;
		stacks->ll_a_start++;		
	}
	scan_for_duplicates(stacks);	
	begin_sort(stacks);
	return (stacks);
}