/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok_ko.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 19:41:44 by cphillip          #+#    #+#             */
/*   Updated: 2020/06/18 11:11:04 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ok(t_stacks *stacks)
{
	if (stacks->color == 1)
		ft_printf(GREEN"OK\n"RESET);
	else
		ft_printf("OK\n");
}

void	ko(t_stacks *stacks)
{
	if (stacks->color == 1)
		ft_printf(RED"KO\n"RESET);
	else
		ft_printf("KO\n");
}
