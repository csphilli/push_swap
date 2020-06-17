/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 19:38:00 by cphillip          #+#    #+#             */
/*   Updated: 2020/06/17 20:39:39 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	help(void)
{
	
	ft_printf(CYAN"X--------------------------------------------X\n");
	ft_printf("%30s", "HELP - OPTIONS\n");
	ft_printf("X--------------------------------------------X\n"RESET);
	ft_printf(YELLOW"-h"RESET);
	ft_printf("\tdisplays this help list.\n");
	ft_printf(YELLOW"-c"RESET);
	ft_printf("\tcoloring of the OK and KO results.\n");
	ft_printf(YELLOW"-ae"RESET);
	ft_printf("\tto enable more descriptive error messages.\n");
	ft_printf(YELLOW"-v"RESET);
	ft_printf("\tto see the program in action. NOTE! Must have\n");
	ft_printf("\t\tPython3 and Quicktime installed.\n");
	ft_printf(YELLOW"-d"RESET);
	ft_printf("\tto display sorted list with node addresses and\n");
	ft_printf("\t\tfinal move count.\n\n");
	ft_printf("End of options descriptions. Please restart program.\n\n");
	exit(0);
}
