/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:20:32 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/09 18:36:08 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// static void	validate_input_str(char *str)
// {

// }

void	exec_parse(t_stacks *stacks, char *str)
{
	if (ft_strequ("sa", str))
		sa(stacks);
	else if (ft_strequ("pa", str))
		pa(stacks);
	else if (ft_strequ("pb", str))
		pb(stacks);
	else if (ft_strequ("ra", str))
		ra(stacks, 0);
	else if (ft_strequ("rb", str))
		rb(stacks, 0);
	else if (ft_strequ("rr", str))
		rr(stacks, 1);
	else if (ft_strequ("rra", str))
		rra(stacks, 0);
	else if (ft_strequ("rrb", str))
		rrb(stacks, 0);
	else if (ft_strequ("rrr", str))
		rrr(stacks, 1);
	else
		ERROR;
	stacks->nbr_moves++;
}

// void	checker(t_stacks *stacks, int ac, char **av)
// {
// 	char	*input_str;

// 	input_str = av[1];
// }
