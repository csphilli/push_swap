/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 09:14:17 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/30 09:16:10 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../src/libft/header/libft.h"
#define ERROR error()

void	error(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

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

t_stacks	*create_stacks(void);
t_lists		*create_new_node(int nbr);
t_stacks	*initialize_stacks(t_stacks *stack);
void		display_list(t_lists *list);
void		insert_node(t_stacks *stacks, int nbr);
void		check_for_duplicates(t_stacks *stacks);

# endif