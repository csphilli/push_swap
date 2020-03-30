/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 09:14:17 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/30 18:55:53 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../libft/header/libft.h"
#define ERROR error()

typedef struct s_lists
{
	int		nbr;
	struct s_lists *next;
}				t_lists;

typedef struct s_stacks
{
	t_lists *head_a;
	t_lists	*head_b;
	int		midpoint;
	int		list_len_start;
	int		nbr_moves;
}				t_stacks;

void        error(void);
t_stacks	*create_stacks(void);
t_lists		*create_new_node(int nbr);
t_stacks	*initialize_stacks(t_stacks *stack);
void		display_list(t_lists *list);
void		insert_node(t_stacks *stacks, int nbr);
void		check_for_duplicates(t_stacks *stacks);
t_lists		*list_pop(t_lists *list);
t_lists		*list_push(int nbr, t_lists *list);
void    	begin_sort(t_stacks *stacks);
t_lists		*first_step(t_stacks *stacks, t_lists *list_a);
t_stacks	*second_step(t_stacks *stacks);
t_lists		*rotate_list(t_stacks *stacks, t_lists *list);
t_lists		*swap_list(t_lists *list);
t_stacks	*pb(t_stacks *stacks);
void		insert_node(t_stacks *stacks, int nbr);
t_stacks	*run_program(t_stacks *stacks, int ac, char **av);
t_stacks    *longer_second_step(t_stacks *stacks);

# endif