/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:55:38 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/14 13:08:26 by csphilli         ###   ########.fr       */
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

	// int	dir_a;
	// int	dir_b;



	cur = b;
	next_move = cur;
	least_moves = 999999;
	while (cur)
	{
		// printf("------------------------\n");
		// printf("\nFINDING NEXT NUMBER\n");
		// dir_a = get_dir(a, next_large(a, cur->nbr));
		// dir_b = get_dir(b, cur->nbr);

		moves = 0;
		check = get_dir(a, next_large(a, cur->nbr)) == get_dir(b, cur->nbr) ? true : false;
		// printf("curr->B: %3d | dir: %3d | moves: %3d\n", cur->nbr, dir_b, to_top(b, cur->nbr));	
		// printf("next->A: %3d | dir: %3d | moves: %3d\n", next_large(a, cur->nbr), dir_a, to_top(a, next_large(a, cur->nbr)));
		
		
		moves = to_top(b, cur->nbr) + to_top(a, next_large(a, cur->nbr)) +
		(dir_mod(a, next_large(a, cur->nbr), b, cur->nbr) * -1);
		// printf("total moves: %d\n", moves);
		// printf("LIST A\n");
		// display_list(a);
		// printf("LIST B\n");
		// display_list(b);
		// printf("------------------------\n");
		if ((moves < least_moves) || (moves <= least_moves && check == true))
		{
			next_move = cur;
			least_moves = moves;
		}
		// printf("current fav: %d | nbr_moves: %d\n", next_move->nbr, least_moves);
		cur = cur->next;
	}
	return (next_move);
}
