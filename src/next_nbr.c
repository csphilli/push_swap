/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 11:35:27 by csphilli          #+#    #+#             */
/*   Updated: 2020/06/23 10:15:13 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Next large takes the number in question from stack b and
**	finds the next largest number from stack a. Two if statements
**	are necessary because the first time the comparison runs,
**	there isn't a value for TMP. The second, and subsequent, comparisons
**	TMP will not be NULL so it will use that if statement to make
**	the comparison.
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
