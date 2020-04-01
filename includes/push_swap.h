/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 09:14:17 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/01 15:13:14 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../libft/header/libft.h"
#define ERROR error()

/*
**	STRUCTS
**	t_lists holds the values for each node.
**	t_stacks holds the head value for each stack.
*/

typedef struct	s_lists
{
	int				nbr;
	struct s_lists 	*next;
}				t_lists;

typedef struct	s_stacks
{
	t_lists			*head_a;
	t_lists			*head_b;
	int				midpoint;
	int				list_a_len_start;
	int				list_len_b;
	int				nbr_moves;
	bool			sorted;
}				t_stacks;

/*
**	ERROR HANDLING FUNCTIONS
*/

void        error(void);

/*
**	GENERAL LIST FUNCTIONS
*/

void		push_a(t_stacks *stacks, int nbr);
void		push_b(t_stacks *stacks, int nbr);
void		pop_a(t_stacks *stacks);
void		pop_b(t_stacks *stacks);
void		unshift_b(t_stacks *stacks, int nbr);
void		unshift_a(t_stacks *stacks, int nbr);

/*
**	ALLOWED LIST MANIPULATIONS
*/

void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void    	sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);
void	    ra(t_stacks *stacks);
void	    rb(t_stacks *stacks);
void	    rr(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);




/*
**	ALGORITHM FUNCTIONS
*/

void    	begin_sort(t_stacks *stacks);
void		first_step(t_stacks *stacks);
void    	second_step(t_stacks *stacks);
void        longer_second_step(t_stacks *stacks);
void		third_step(t_stacks *stacks);
void		fourth_step(t_stacks *stacks);
void		fifth_step(t_stacks *stacks);

t_stacks	*create_stacks(void);
t_lists		*create_new_node(int nbr);
t_stacks	*initialize_stacks(t_stacks *stack);
void		display_list(t_lists *list);
// void		insert_node(t_stacks *stacks, int nbr);
void		check_for_duplicates(t_stacks *stacks);
void		check_order(t_stacks *stacks);
// t_lists		*list_pop(t_lists *list);
// t_lists		*list_push(int nbr, t_lists *list);


// t_lists		*first_step(t_stacks *stacks, t_lists *list_a);

// t_stacks	*second_step(t_stacks *stacks);

// t_stacks	*pb(t_stacks *stacks);
void		insert_node(t_stacks *stacks, int nbr);
t_stacks	*run_program(t_stacks *stacks, int ac, char **av);

// t_stacks    *longer_second_step(t_stacks *stacks);

# endif