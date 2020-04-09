/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:55:38 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/09 14:49:10 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lists *get_next(t_lists *a, t_lists *b)
{	
	int least_moves;
	int moves;
	t_lists *cur;
	t_lists	*next_move;
	bool check;

	cur = b;
	next_move = cur;
	least_moves = 999999;
	while (cur)
	{
		moves = 0;
		check = get_dir(a, next_large(a, cur->nbr)) == get_dir(b, cur->nbr) ? true : false;		
		moves = to_top(b, cur->nbr) + to_top(a, next_large(a, cur->nbr)) +
		(dir_mod(a, next_large(a, cur->nbr), b, cur->nbr) * -1);		
		if (moves < least_moves || (moves <= least_moves && check == true))
		{
			next_move = cur;
			least_moves = moves;
		}
		cur = cur->next;
	}
	return (next_move);
}
