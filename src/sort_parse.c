/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 14:41:13 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/31 10:58:50 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	begin_sort(t_stacks *stacks)
{
	// printf("BEGIN SORT\n");
	first_step(stacks); // sorting correctly.
    // stacks->head_a = first_step(stacks, stacks->head_a); // sorting correctly.
	// printf("2nd STEP\n");
	second_step(stacks); // sorting correctly!
	// stacks = second_step(stacks); // sorting correctly!
}
