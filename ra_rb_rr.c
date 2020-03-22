/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 12:05:30 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/22 12:08:51 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// includes here

t_lista		*ra(t_lista *list)
{
	t_lista	*head;
	t_lista *tail;
	t_lista	*tmp;

	head = list;
	tail = head;
	tmp = head;
	if (head == NULL || head->next == NULL)
		ERROR;
	if (tmp->next == NULL)
		head = sa(head);
	else
	{
		while (tail->next != NULL)
			tail = tail->next;
		tmp = tmp->next;
		head->next = NULL;
		tail->next = head;
		head = tmp;
	}
	return (head);
}

t_lista		*rb(t_lista *list)
{
	t_lista	*head;
	t_lista *tail;
	t_lista	*tmp;

	head = list;
	tail = head;
	tmp = head;
	if (head == NULL || head->next == NULL)
		ERROR;
	if (tmp->next == NULL)
		head = sb(head);
	else
	{
		while (tail->next != NULL)
			tail = tail->next;
		tmp = tmp->next;
		head->next = NULL;
		tail->next = head;
		head = tmp;
	}
	return (head);
}

t_lista     *rr(t_lista *lista, t_lista *listb)
{
    ra(lista);
    rb(listb);
}