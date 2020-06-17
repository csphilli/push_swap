/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 13:59:06 by cphillip          #+#    #+#             */
/*   Updated: 2020/06/17 14:28:05 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	options(t_stacks *stacks, char **av)
{
	ft_printf("stacks->help: %c", stacks->help);
	if(ft_strcmp("-c", ft_itoa(*av[1])))
		ft_printf("success! *av[1] = %s", av[1]);
	else
		ft_printf("failure\n");
}