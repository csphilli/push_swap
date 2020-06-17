/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 13:20:42 by csphilli          #+#    #+#             */
/*   Updated: 2020/06/17 20:53:09 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Error functions. 
*/

void	error(void)
{
	ft_printf("Error\n");
	exit(-1);
}

void	invalid_cmd(void)
{
	ft_printf("Error: Invalid Command entered. Acceptable commands\n");
	ft_printf("are: SA SB SS RA RB RR RRA RRB RRR\n\n");
	ft_printf("Please try again.\n");
	exit(-1);
}
