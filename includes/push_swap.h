/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 09:14:17 by csphilli          #+#    #+#             */
/*   Updated: 2020/06/18 12:25:21 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include "../libft/header/libft.h"
# include "../libft/ft_printf/includes/ft_printf.h"
# define ERROR "Error\n"
# define ER_INV_CMD "Error: Invalid entry. Use sa sb ss ra rb rr rra rrb rrr.\n"
# define ER_A_EMP "Error: Stack A has 1 or 0 values. Cannot execute command.\n"
# define ER_B_EMP "Error: Stack B has 1 or 0 values. Cannot execute command.\n"
# define ER_GNL "Error: Get Next Line failed to parse in checker function.\n"
# define ER_INV_INPUT "Error: Invalid inputs.\n"
# define ER_DUP "Error: Duplicate value found.\n"
# define ER_MALLOC "Error: Failed to allocate memory.\n"
# define ER_NAN "Error: Not a valid integer.\n"
# define ER_SIZE "Error: Number is not a valid INT size.\n"

/*
**	STRUCTS
**	t_lists holds the values for each node.
**	t_stacks holds the head value for each stack plus other
**	variables.
*/

typedef struct		s_lists
{
	int				nbr;
	struct s_lists	*next;
}					t_lists;

typedef struct		s_stacks
{
	t_lists			*head_a;
	t_lists			*head_b;
	int				ll_a_start;
	int				ll_a_cur;
	int				ll_b_cur;
	bool			full_sort;
	bool			a_sorted;
	bool			b_sorted;
	int				moves_a;
	int				moves_b;
	int				pos_a_min;
	int				pos_a_max;
	int				dir_a;
	int				dir_b;
	int				a_max;
	int				a_min;
	int				help;
	int				color;
	int				advanced;
	int				nbr_moves;
}					t_stacks;

/*
**	ERROR HANDLING FUNCTIONS
*/

void				error(void);

/*
**	GENERAL LIST FUNCTIONS
*/

void				push_a(t_stacks *stacks, int nbr);
void				pop_a(t_stacks *stacks);
void				pop_b(t_stacks *stacks);
void				unshift_b(t_stacks *stacks, int nbr);
void				unshift_a(t_stacks *stacks, int nbr);

/*
**	ALLOWED LIST MANIPULATIONS
*/

void				pa(t_stacks *stacks, int toggle);
void				pb(t_stacks *stacks, int toggle);
void				sa(t_stacks *stacks, int toggle);
void				sb(t_stacks *stacks, int toggle);
void				ss(t_stacks *stacks, int toggle);
void				ra(t_stacks *stacks, int toggle);
void				rb(t_stacks *stacks, int toggle);
void				rr(t_stacks *stacks, int toggle);
void				rra(t_stacks *stacks, int toggle);
void				rrb(t_stacks *stacks, int toggle);
void				rrr(t_stacks *stacks, int toggle);

/*
**	UTILITY FUNCTIONS
*/

void				ok(t_stacks *stacks);
void				ko(t_stacks *stacks);
void				help(void);
t_stacks			*parsing(t_stacks *stacks, int ac, char **av);
void				exec_parse(t_stacks *stacks, const char *str);
int					get_midpoint(t_lists *list);
int					ll(t_lists *list);
t_stacks			*create_stacks(void);
t_stacks			*initialize_stacks(t_stacks *stack);
t_lists				*create_new_node(int nbr);
void				init_min_max(t_stacks *stacks);
void				display_list(t_lists *list);
void				scan_for_duplicates(t_stacks *stacks);
void				scan_for_min_max(t_stacks *stacks);
void				check_order_a(t_stacks *stacks);
void				check_order_b(t_stacks *stacks);
void				check_full_sort(t_stacks *stacks);
int					get_dir(t_lists *list, int nbr);
int					dir_mod(t_lists *list_a, int next_nbr,\
					t_lists *list_b, int nbr);
void				insert_node(t_stacks *stacks, int nbr);
t_stacks			*run_program(t_stacks *stacks, int ac, char **av);
t_stacks			*parse_array(t_stacks *stacks, int ac, char **av);
t_stacks			*parse_string(t_stacks *stacks, char *str);
void				free_list_a(t_stacks *stacks);
void				options(t_stacks *stacks, char **av);

/*
**	ALGORITHM FUNCTIONS
*/

void				sort_5_and_6(t_stacks *stacks);
int					to_top(t_lists *list, int nbr);
t_lists				*get_next(t_lists *list_a, t_lists *list_b);
int					next_large(t_lists *list, int nbr);
int					find_median(t_stacks *stacks, t_lists *list_a);
void				the_big_sort(t_stacks *stacks);
void				sort_a_to_b(t_stacks *stacks);
void				sort_b_to_a(t_stacks *stacks);
void				min_max_a(t_stacks *stacks);
void				min_max_b(t_stacks *stacks);
void				begin_sort(t_stacks *stacks);
void				sort_short(t_stacks *stacks);
void				sort_three_numbers(t_stacks *stacks);
void				sort_two_numbers(t_stacks *stacks);

#endif
