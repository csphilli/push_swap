/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:24:27 by cphillip          #+#    #+#             */
/*   Updated: 2020/06/18 14:24:50 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	invalid_input(t_stacks *stacks, char *str)
{
	if (stacks->advanced == 1)
	{
		ft_printf(ER_NAN" Found: "YELLOW"%s\n", str);
		exit(-1);
	}
	else
	{
		ft_printf(ERROR);
		exit(-1);
	}
}
