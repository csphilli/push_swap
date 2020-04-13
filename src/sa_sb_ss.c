/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:41:20 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/13 18:03:46 by csphilli         ###   ########.fr       */
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

void		sb(t_stacks *stacks, int toggle)
{
	t_lists *head;
	t_lists *second;

	head = stacks->head_b;
	second = head;
	if (second->next != NULL)
	{
		second = second->next;
		if (second->next != NULL)
		{
			head->next = second->next;
			second->next = head;
			stacks->head_b = second;
		}
		else
		{
			second->next = head;
			head->next = NULL;
			stacks->head_b = second;
		}
		if (toggle == 0)
			ft_putendl("sb");
	}
}

void	ss(t_stacks *stacks, int toggle)
{
	sa(stacks, 1);
	sb(stacks, 1);
	if (toggle == 0)
		ft_putendl("ss");
}
