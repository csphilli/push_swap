/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 09:14:17 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/09 18:35:37 by csphilli         ###   ########.fr       */
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
	int				ll_a_start;
	int				ll_a_cur;
	int				ll_b_cur;
	int				nbr_moves; // only needed to check my stats. delete before submission
	bool			full_sort;
	bool			a_sorted; // might not need
	bool			b_sorted; // might not need.
	int				moves_a;
	int				moves_b;
	int				pos_a_min;
	int				pos_a_max;
	int				dir_a;
	int				dir_b;
	int				a_max;
	int				a_min;
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
void	    ra(t_stacks *stacks, int nbr);
void	    rb(t_stacks *stacks, int nbr);
void	    rr(t_stacks *stacks, int nbr);
void		rra(t_stacks *stacks, int nbr);
void		rrb(t_stacks *stacks, int nbr);
void		rrr(t_stacks *stacks, int nbr);

/*
**	Utility functions
*/
t_stacks 	*parsing(t_stacks *stacks, int ac, char **av);
void		exec_parse(t_stacks *stacks, char *str);
int			get_midpoint(t_lists *list);
int			ll(t_lists *list);
t_stacks	*create_stacks(void);
t_stacks	*initialize_stacks(t_stacks *stack);
t_lists		*create_new_node(int nbr);
void		init_min_max(t_stacks *stacks);
void		display_list(t_lists *list);
void		scan_for_duplicates(t_stacks *stacks);
void		scan_for_min_max(t_stacks *stacks);
void		display_moves(t_stacks *stacks); // remove before submission
void		print_min_max_lists(t_stacks *stacks); // remove before submission
void		check_order_a(t_stacks *stacks);
void		check_order_b(t_stacks *stacks);
void		check_full_sort(t_stacks *stacks);
int			get_dir(t_lists *list, int nbr);
int			dir_mod(t_lists *list_a, int next_nbr, t_lists *list_b, int nbr);
void		insert_node(t_stacks *stacks, int nbr);
t_stacks	*run_program(t_stacks *stacks, int ac, char **av);
t_stacks	*parse_array(t_stacks *stacks, int ac, char **av);
t_stacks	*parse_string(t_stacks *stacks, char *str);

/*
**	ALGORITHM FUNCTIONS
*/

int			to_top(t_lists *list, int nbr);
t_lists 	*get_next(t_lists *list_a, t_lists *list_b);
int			next_large(t_lists *list, int nbr);
int			find_median(t_lists *list_a);
void		the_big_sort(t_stacks *stacks);
void		sort_a_to_b(t_stacks *stacks);
void		sort_b_to_a(t_stacks *stacks);
void		min_max_a(t_stacks *stacks);
void		min_max_b(t_stacks *stacks);
void    	begin_sort(t_stacks *stacks);
void		sort_short(t_stacks *stacks);
void		sort_three_numbers(t_stacks *stacks);
void		sort_two_numbers(t_stacks *stacks);

# endif