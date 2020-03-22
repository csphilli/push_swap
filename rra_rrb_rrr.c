/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 12:21:04 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/22 12:22:14 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// includes

t_lista		*rra(t_lista *list)
{
	t_lista	*head;
	t_lista *tail;
	t_lista	*tmp;

	head = list;
	tail = head;
	tmp = head;
	if (head == NULL || head->next == NULL)
		ERROR;
	tmp = tmp->next;
	if (tmp->next == NULL)
		head = sa(head);
	else
	{
		while (tail->next != NULL)
			tail = tail->next;
		while (tmp->next != tail)
			tmp = tmp->next;
		tail->next = head;
		tmp->next = NULL;
		head = tail;
	}
	return (head);
}

t_lista		*rrb(t_lista *list)
{
	t_lista	*head;
	t_lista *tail;
	t_lista	*tmp;

	head = list;
	tail = head;
	tmp = head;
	if (head == NULL || head->next == NULL)
		ERROR;
	tmp = tmp->next;
	if (tmp->next == NULL)
		head = sb(head);
	else
	{
		while (tail->next != NULL)
			tail = tail->next;
		while (tmp->next != tail)
			tmp = tmp->next;
		tail->next = head;
		tmp->next = NULL;
		head = tail;
	}
	return (head);
}