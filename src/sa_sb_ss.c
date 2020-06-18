/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 18:41:20 by csphilli          #+#    #+#             */
/*   Updated: 2020/06/18 10:43:41 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	stack_error(t_stacks *stacks, char *i)
{
	if (ft_strequ("a", i))
		stacks->advanced == 1 ? ft_printf(ER_A_EMP) : ft_printf(ERROR);
	else if (ft_strequ("b", i))
		stacks->advanced == 1 ? ft_printf(ER_B_EMP) : ft_printf(ERROR);
	exit(-1);
}

void		sa(t_stacks *stacks, int toggle)
{
	t_lists *head;
	t_lists *second;

	head = stacks->head_a;
	second = head;
	if (second && second->next != NULL)
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
	else
		stack_error(stacks, "a");
}

void		sb(t_stacks *stacks, int toggle)
{
	t_lists *head;
	t_lists *second;

	head = stacks->head_b;
	second = head;
	if (second && second->next != NULL)
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
	else
		stack_error(stacks, "b");
}

void		ss(t_stacks *stacks, int toggle)
{
	sa(stacks, 1);
	sb(stacks, 1);
	if (toggle == 0)
		ft_putendl("ss");
}
