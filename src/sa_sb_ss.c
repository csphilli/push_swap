/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:41:20 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/31 12:47:18 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		sa(t_stacks *stacks)
{
	// printf("SWAP LIST - LIST START\n");
	t_lists *head;
	t_lists *second;

	head = stacks->head_a;
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
			stacks->head_a = head;
		}
		else
		{
			second->next = head;
			head->next = NULL;
			head = second;
			stacks->head_a = head;
		}		
	}
	// printf("SWAP LIST - LIST END\n");
	// display_list(head);
	// return (head);	
}

void		sb(t_stacks *stacks)
{
	// printf("SWAP LIST - LIST START\n");
	t_lists *head;
	t_lists *second;

	head = stacks->head_b;
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
			stacks->head_b = head;
		}
		else
		{
			second->next = head;
			head->next = NULL;
			head = second;
			stacks->head_b = head;
		}		
	}
	// printf("SWAP LIST - LIST END\n");
	// display_list(head);
	// return (head);	
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}