/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 13:20:42 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/13 16:16:18 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Basic error function. Could use some elaboration at various parts of the
**	program. Simly printing "Errror" isn't going to specifically say WHERE
**	the error occured. This is default for the instructions though.
*/

void	error(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}
