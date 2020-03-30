/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 14:48:27 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/30 18:55:33 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stacks *longer_second_step(t_stacks *stacks)
{
	t_stacks *tmp;
	t_lists	*head_a;
	t_lists	*tail_a;

	tmp = stacks;
	head_a = tmp->head_a;
	tail_a = tmp->head_a;
	while (tail_a->next != NULL)
		tail_a = tail_a->next;
	if (head_a->nbr < tail_a->nbr)
	{
		tmp = pb(tmp);
		// printf("VERIFYING LISTS AFTER RETURN FROM PB\n");
		// display_list(tmp->head_a);
		// display_list(tmp->head_b);
		tmp->midpoint++;
		// printf("MIDPOINT VALUE:%d\n", tmp->midpoint);
	}
	else
    {
        // write(1, "sa\n", 3); THis needs to be interpretted by checker
		tmp->head_a = swap_list(tmp->head_a);
    }
	tmp->head_a = rotate_list(tmp, tmp->head_a);
	// printf("LISTS AFTER LONGER SECOND STEP\n");
	// display_list(tmp->head_a);
	// printf("\n");
	// display_list(tmp->head_b);
	return (tmp);
}

t_stacks	*second_step(t_stacks *stacks)
{
	bool        check;
	t_stacks    *tmp;
	t_lists     *head_a;
	t_lists     *tail_a;
	int         i;

	i = 1;
	tmp = stacks;
	head_a = tmp->head_a;
	tail_a = tmp->head_a;
	check = true;
	while (check)
	{
		// printf("SECOND STEP START - ROUND %d\n", i);
		// printf("LIST A START\n");
		// display_list(tmp->head_a);
		// printf("LIST B START\n");
		// display_list(tmp->head_b);
		// printf("seg fault thrice\n");
		i++;
		tail_a = tmp->head_a;
		head_a = tmp->head_a;
		// printf("seg fault fourth\n");
		while (tail_a->next != NULL)
			tail_a = tail_a->next;
		// printf("tail_a->nbr:%d\n", tail_a->nbr);
		// printf("head_a->nbr:%d | ", head_a->nbr);
		// printf("head_a->next->nbr:%d | ", head_a->next->nbr);
		// printf("tail_a->nbr:%d\n", tail_a->nbr);
		if (head_a->nbr > head_a->next->nbr && head_a->nbr < tail_a->nbr)
		{
			// printf("FIRST IF - SWAP A - START LIST\n");
			// display_list(tmp->head_a);
			tmp->head_a = swap_list(tmp->head_a);
			// printf("FIRST IF - SWAP A - RESULT\n");
			// display_list(tmp->head_a);
			// tmp->head_a = swap_list(tmp->head_a);
		}
		else if (head_a->nbr > head_a->next->nbr && head_a->nbr > tail_a->nbr)
		{
			// printf("SECOND IF - ROTATE A\n");
			tmp->head_a = rotate_list(tmp, tmp->head_a);
			// printf("SECOND IF - ROTATE A - RESULT\n");
			// display_list(tmp->head_a);
			// tmp->head_a = rotate_list(tmp->head_a);
		}
		else if (head_a->next->nbr > tail_a->nbr && head_a->next != NULL)
		{
			// printf("SENT TO LONG SECOND STEP\n");
			tmp = longer_second_step(tmp);
			// printf("VERIFYING LISTS RETURNED TO LONG 2nd STEP\n");
			// display_list(tmp->head_a);
			// display_list(tmp->head_b);

		}
		else
		{
			// printf("CHANGING TO FALSE\n");
			check = false;
		}
	}
	return (tmp);
}
