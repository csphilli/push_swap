/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 14:18:23 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/30 14:19:41 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lists		*list_pop(t_lists *list)
{
	// printf("POP LIST - LIST START\n");
	
	t_lists *tmp;
	t_lists *head;

	head = list;
	tmp = head;
	// display_list(head);
	head = tmp->next;
	tmp->nbr = '\0';
	tmp->next = NULL;
	free(tmp);
	// printf("POP LIST - AFTER POP\n");
	// display_list(head);
	return (head);
}

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