/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifth_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 11:07:38 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/01 20:58:30 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_singles_a(t_stacks *stacks)
{
	// printf("CHECK SINGLES A - START\n");
	t_lists *tail_a_prev;

	tail_a_prev = stacks->head_a;	
	// printf("tail_a_prev->nbr:%d\n", tail_a_prev->nbr);
	if (stacks->head_a && stacks->head_a->next != NULL)
	{
		if (tail_a_prev->next->next && tail_a_prev->next->next == NULL)
			tail_a_prev = stacks->head_a;
		else	
			while (tail_a_prev->next->next != NULL)
				tail_a_prev = tail_a_prev->next;
		// printf("inside if\n");
		if (stacks->head_a->nbr > stacks->head_a->next->nbr &&\
				stacks->head_a->nbr > tail_a_prev->next->nbr)
				ra(stacks);
		else if (tail_a_prev->next->nbr < tail_a_prev->nbr)
				rra(stacks);
		else if (stacks->head_a->nbr > stacks->head_a->next->nbr)
				sa(stacks);
	}
	// printf("LIST A END OF SINGLES A\n");
	// display_list(stacks->head_a);
}

static void	check_singles_b(t_stacks *stacks)
{
	// printf("CHECK SINGLES B - START\n");
	t_lists *tail_b_prev;

	tail_b_prev = stacks->head_b;
	// printf("tail_b_prev->nbr:%d\n", tail_b_prev->nbr);
	
	// printf("tail_b_prev->nbr:%d\n", tail_b_prev->nbr);
	// printf("tail_b_prev->next->nbr:%d\n", tail_b_prev->next->nbr);
	if (stacks->head_b && stacks->head_b->next != NULL)
	{
		if (tail_b_prev->next == NULL)
			tail_b_prev = stacks->head_b;
		else	
			while (tail_b_prev->next->next != NULL)
				tail_b_prev = tail_b_prev->next;
		// printf("inside if\n");
		if (stacks->head_b->nbr < stacks->head_b->next->nbr &&\
			stacks->head_b->nbr < tail_b_prev->next->nbr)
			rb(stacks);
		else if (tail_b_prev->next->nbr > tail_b_prev->nbr)
		{
			// printf("hit rrb\n");
			rrb(stacks);
		}
		else if (stacks->head_b->nbr < stacks->head_b->next->nbr)
			sb(stacks);
		// else
		// 	printf("didn't catch anything?\n");
	}
	// printf("LIST B END OF SINGLES B\n");
	// display_list(stacks->head_b);
}

static void	check_double_swaps(t_stacks *stacks)
{
	// printf("CHECK DOUBLES SWAPS - START\n");
	if (stacks->head_a && stacks->head_b &&\
		stacks->head_a->next && stacks->head_b->next)
	{
		// printf("inside if\n");
		if (stacks->head_a->nbr > stacks->head_a->next->nbr &&\
			stacks->head_b->nbr < stacks->head_b->next->nbr)
			ss(stacks);
		if (stacks->head_a->nbr > stacks->head_a->next->nbr)
			sa(stacks);
		else if (stacks->head_b->nbr < stacks->head_b->next->nbr)
			sb(stacks);
	}
}

void	fifth_step(t_stacks *stacks)
{
	int i;
	bool	check;
	// t_lists *tail_a_prev;
	// t_lists *tail_b_prev;

	// printf("BEGIN OF FIFTH STEP\nLIST A\n");
	// display_list(stacks->head_a);
	// printf("LIST B\n");
	// display_list(stacks->head_b);
	i = 1;
	check = true;
	while (check)
	{
		// printf("ROUND %d\n", i);
		// printf("stacks->list_len_b at round %d: %d\n", i, stacks->list_len_b);
		check_singles_a(stacks);
		check_singles_b(stacks);
		check_double_swaps(stacks);
		
		if (stacks->head_a->nbr < stacks->head_b->nbr && stacks->head_b != NULL)
			pb(stacks);
		else if (stacks->head_b != NULL)
			pa(stacks);
		// printf("END OF FIFTH STEP - RESULTS!\nLIST A\n");
		// display_list(stacks->head_a);
		// printf("LIST B\n");
		// display_list(stacks->head_b);
		i++;
		if (stacks->list_len_b == 0)
			check = false;
	}
}