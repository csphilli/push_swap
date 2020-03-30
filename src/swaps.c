/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:41:20 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/30 18:49:10 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**  Similar to the rotate list functions, swap_list operates with only a single function.
**  Whichever list you want to rotate is passed as the argument.
**  Now that I think of it, i may have to actually code them individually since checker
**  wont know which one to do.
*/

t_lists		*swap_list(t_lists *list)
{
	// printf("SWAP LIST - LIST START\n");
	t_lists *head;
	t_lists *second;

	head = list;
	second = head;
	// display_list(head);
	if (second->next != NULL)
	{
		second = second->next;
		if (second->next != NULL)
		{
			head->next = second->next;
			second->next = head;
			head = second;
		}
		else
		{
			second->next = head;
			head->next = NULL;
			head = second;
		}		
	}
	// printf("SWAP LIST - LIST END\n");
	// display_list(head);
	return (head);	
}
