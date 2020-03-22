/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 21:19:20 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/22 13:55:12 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    INCLUDES HERE
*/

t_lista	 *sa(t_lista *list)
{
	t_lista	*head;
	t_lista *current;

	head = list;
	current = head;
	if (head == NULL || head->next == NULL)
		ERROR;
	current = current->next;
	if (current->next != NULL)
	{
		head->next = current->next;
		current->next = head;
		head = current;
	}
	else
	{
		current->next = head;
		head->next = NULL;
		head = current;		
	}
	return (head);
}

t_lista	 *sb(t_lista *list)
{
	t_lista	*head;
	t_lista *current;

	head = list;
	current = head;
	if (head == NULL || head->next == NULL)
		ERROR;
	current = current->next;
	if (current->next != NULL)
	{
		head->next = current->next;
		current->next = head;
		head = current;
	}
	else
	{
		current->next = head;
		head->next = NULL;
		head = current;		
	}
	return (head);
}

void    ss(t_lista *lista, t_listb *listb)
{
    sa(lista);
    sb(listb);
}