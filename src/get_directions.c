/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_directions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:31:42 by csphilli          #+#    #+#             */
/*   Updated: 2020/06/15 13:33:39 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Pretty self explanatory.
*/

int	get_midpoint(t_lists *list)
{
	return (ll(list) / 2);
}

/*
**	ll (ell ell - list length) just computers the current length of the
**	list to help evaluate the midpoint. This would be nicer if we weren't
**	restricted with lame line counts per function.
*/

int	ll(t_lists *list)
{
	int len;

	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

/*
**	To top takes a number as an argument and counts how many moves
**	it'll take in order for the number to be placed at the top of the
**	list. It takes into account whether it's faster to use normal rotation
**	or reverse rotation.
*/

int	to_top(t_lists *list, int nbr)
{
	int		moves;
	t_lists *tmp;

	moves = 0;
	tmp = list;
	while (tmp && tmp->nbr != nbr)
	{
		tmp = tmp->next;
		moves++;
	}
	if (moves == 0)
		return (0);
	else if (moves <= get_midpoint(list))
		return (moves);
	else
		return (ll(list) - moves);
}

/*
**	Get dir takes the current number being examined as an argument and evaluates
**	whether it's shorter to get to the top of the list via rotation or
**	reverse rotation. Returning a value of 1 indicates it's shorter to use
**	rotation.
*/

int	get_dir(t_lists *list, int nbr)
{
	t_lists	*tmp;
	int		i;

	i = 0;
	tmp = list;
	if (tmp)
	{
		while (tmp)
		{
			if (tmp->nbr == nbr)
				break ;
			tmp = tmp->next;
			i++;
		}
		if (i <= get_midpoint(list))
			return (1);
	}
	return (0);
}
