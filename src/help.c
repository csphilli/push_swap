/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 19:38:00 by cphillip          #+#    #+#             */
/*   Updated: 2020/06/18 14:48:18 by cphillip         ###   ########.fr       */
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
	ft_printf("\tto enable more descriptive error messages.\n\n");
	ft_printf("End of options descriptions. Please restart program.\n\n");
	exit(0);
}
