/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_directions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:31:42 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/09 14:48:17 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_midpoint(t_lists *list)
{
	return (ll(list) / 2);
}

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

int	get_dir(t_lists *list, int nbr)
{
	t_lists	*tmp;
	int 	i;

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
