/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:41:20 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/13 15:13:54 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Only used sa when I pushed the list to stack_b in the beginning.
*/

void		sa(t_stacks *stacks, int toggle)
{
	t_lists *head;
	t_lists *second;

	head = stacks->head_a;
	second = head;
	if (second->next != NULL)
	{
		second = second->next;
		if (second->next != NULL)
		{
			head->next = second->next;
			second->next = head;
			stacks->head_a = second;
		}
		else
		{
			second->next = head;
			head->next = NULL;
			stacks->head_a = second;
		}
		if (toggle == 0)
			ft_putendl("sa");
	}
}
