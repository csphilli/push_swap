/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop_unshift.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 14:18:23 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/04 17:02:26 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		pop_a(t_stacks *stacks)
{
	// printf("POP LIST - LIST START\n");
	
	t_lists *tmp;
	t_lists *head;

	head = stacks->head_a;
	tmp = head;
	// display_list(head);
	head = tmp->next;
	tmp->nbr = '\0';
	tmp->next = NULL;
	stacks->head_a = head;
	free(tmp);
	// printf("POP LIST - AFTER POP\n");
	// display_list(head);
	// return (head);
}

void		pop_b(t_stacks *stacks)
{
	// printf("POP LIST - LIST START\n");
	t_lists *head;
	t_lists *tmp;

	head = stacks->head_b;
	tmp = head;
	// display_list(head);
	if (tmp->next != NULL)
	{
		head = tmp->next;
		tmp->next = NULL;
		stacks->head_b = head;
	}
	else
		stacks->head_b = NULL;
	// stacks->head_b = head;
	free(tmp);
	// printf("POP LIST - AFTER POP\n");
	// display_list(head);
	// printf("no list?\n");
	// return (head);
}

// t_lists		*list_pop(t_lists *list)
// {
// 	// printf("POP LIST - LIST START\n");
	
// 	t_lists *tmp;
// 	t_lists *head;

// 	head = list;
// 	tmp = head;
// 	// display_list(head);
// 	head = tmp->next;
// 	tmp->nbr = '\0';
// 	tmp->next = NULL;
// 	free(tmp);
// 	// printf("POP LIST - AFTER POP\n");
// 	// display_list(head);
// 	return (head);
// }

t_lists		*list_push(int nbr, t_lists *list)
{
	// printf("PUSH LIST - LIST START\n");	
	// printf("nbr sent:%d\n", nbr);
	t_lists	*head;
	t_lists *tmp;
	t_lists	*node;

	head = list;
	tmp = head;
	display_list(head);
	node = create_new_node(nbr);
	if (!list)
		head = node;
	else
	{
		node->next = head;
		head = node;
	}
	// printf("PUSH LIST - LIST AFTER PUSH\n");
	// display_list(head);
	return (head);
}

void		push_a(t_stacks *stacks, int nbr)
{
	t_lists *tmp;
	t_lists *node;

	node = create_new_node(nbr);
	tmp = stacks->head_a;
	if (stacks && node)
	{
		if (!stacks->head_a)
			stacks->head_a = node;
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = node;
		}
		// stacks->list_len_start++;
	}
}

void		push_b(t_stacks *stacks, int nbr)
{
	t_lists *tmp;
	t_lists *node;

	node = create_new_node(nbr);
	tmp = stacks->head_b;
	if (stacks && node)
	{
		if (!stacks->head_b)
			stacks->head_b = node;
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = node;
		}
		// stacks->list_len_start++;
	}
}

void	unshift_b(t_stacks *stacks, int nbr)
{
	t_lists	*node;

	node = create_new_node(nbr);
	if (stacks->head_a && node)
	{
		if (!stacks->head_b)
			stacks->head_b = node;
		else
		{
			node->next = stacks->head_b;
			stacks->head_b = node;
		}
	}
}

void	unshift_a(t_stacks *stacks, int nbr)
{
	t_lists	*node;

	node = create_new_node(nbr);
	if (stacks->head_b && node)
	{
		if (!stacks->head_a)
			stacks->head_a = node;
		else
		{
			node->next = stacks->head_a;
			stacks->head_a = node;
		}
	}
}