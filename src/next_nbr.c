/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 11:35:27 by csphilli          #+#    #+#             */
/*   Updated: 2020/06/15 13:33:12 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Next large takes the number in question from stack b and
**	finds the next largest number from stack a.
*/

int	next_large(t_lists *list, int nbr)
{
	t_lists *tmp;

	tmp = NULL;
	while (list)
	{
		if (list->nbr > nbr && tmp == NULL)
			tmp = list;
		if (list->nbr > nbr && list->nbr < tmp->nbr && tmp != NULL)
			tmp = list;
		list = list->next;
	}
	return (tmp->nbr);
}